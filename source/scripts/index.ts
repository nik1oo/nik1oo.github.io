import * as base from "./base.js";

//@builtin(vertex_index) is the vertex index. Use this for rect shader.

const shader_code = `
@vertex
fn vertexMain(@location(0) coords: vec2f) -> @builtin(position) vec4f {
	return vec4f(coords, 0.0, 1.0); }

@fragment
fn fragmentMain() -> @location(0) vec4f {
	return vec4f(1.0, 0.647, 0.0, 1.0); }
`;

async function main(): Promise<void> {
	var device: GPUDevice | null;
	var context: GPUCanvasContext | null;
	var canvas_format: GPUTextureFormat;
	var encoder: GPUCommandEncoder | null;
	var vertex_buffer: GPUBuffer;
	var buffer_layout: GPUVertexBufferLayout;
	var color_attachment: GPURenderPassColorAttachment;
	var renderpass_encoder: GPURenderPassEncoder;
	var primitive: GPUPrimitiveState;
	var shader_module: GPUShaderModule;
	var render_pipeline: GPURenderPipeline;
	const vertex_data: Float32Array = new Float32Array([ 0.0,  0.5, -0.5, -0.5, 0.5, -0.5 ]);

	if (! base.checkWebgpuSupport()) return;
	device = await base.getGpuDevice(); if (! device) return;
	({ context: context, format: canvas_format } = base.getCanvasContext("canvas-1", device)); if (! context) return;
	encoder = base.getCommandEncoder(device); if (! encoder) return;
	color_attachment = { view: context.getCurrentTexture().createView(), loadOp: "clear",
		clearValue: { r: 0.5, g: 0.0, b: 0.0, a: 1.0 }, storeOp: "store" };
	renderpass_encoder = encoder.beginRenderPass({ colorAttachments: [ color_attachment ] }); if (! renderpass_encoder) return;

	vertex_buffer = device.createBuffer({
		size: vertex_data.byteLength,
		usage: GPUBufferUsage.VERTEX | GPUBufferUsage.COPY_DST }); if (! vertex_buffer) return;
	device.queue.writeBuffer(vertex_buffer, 0, vertex_data.buffer);
	buffer_layout = { arrayStride: 8, attributes: [ { format: "float32x2", offset: 0, shaderLocation: 0 } ] };

	shader_module = device.createShaderModule({ code: shader_code });
	if (shader_module == null) throw new Error("Failed to create Shader Module.");
	render_pipeline = device.createRenderPipeline({
		layout: "auto", primitive: { topology: "triangle-strip", stripIndexFormat: "uint32", frontFace: "ccw", cullMode: "back" },
		vertex: { module: shader_module, entryPoint: "vertexMain", buffers: [ buffer_layout ] },
		fragment: { module: shader_module, entryPoint: "fragmentMain", targets: [{ format: canvas_format }] } });
	renderpass_encoder.setPipeline(render_pipeline);
	renderpass_encoder.setVertexBuffer(0, vertex_buffer);
	renderpass_encoder.draw(3);
	renderpass_encoder.end();
	device.queue.submit([ encoder.finish() ]);
	console.log("Done.");
	return; }

main();
