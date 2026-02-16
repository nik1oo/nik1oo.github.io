"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
const base = __importStar(require("./base.js"));
const shader_code = `
@vertex
fn vertexMain(@location(0) coords: vec2f) -> @builtin(position) vec4f {
	return vec4f(coords, 0.0, 1.0); }

@fragment
fn fragmentMain() -> @location(0) vec4f {
	return vec4f(1.0, 0.647, 0.0, 1.0); }
`;
async function main() {
    var device;
    var context;
    var canvas_format;
    var encoder;
    var vertex_buffer;
    var buffer_layout;
    var color_attachment;
    var renderpass_encoder;
    var primitive;
    var shader_module;
    var render_pipeline;
    const vertex_data = new Float32Array([0.0, 0.5, -0.5, -0.5, 0.5, -0.5]);
    if (!base.checkWebgpuSupport())
        return;
    device = await base.getGpuDevice();
    if (!device)
        return;
    ({ context: context, format: canvas_format } = base.getCanvasContext("canvas-1", device));
    if (!context)
        return;
    encoder = base.getCommandEncoder(device);
    if (!encoder)
        return;
    color_attachment = { view: context.getCurrentTexture().createView(), loadOp: "clear",
        clearValue: { r: 0.5, g: 0.0, b: 0.0, a: 1.0 }, storeOp: "store" };
    renderpass_encoder = encoder.beginRenderPass({ colorAttachments: [color_attachment] });
    if (!renderpass_encoder)
        return;
    vertex_buffer = device.createBuffer({
        size: vertex_data.byteLength,
        usage: GPUBufferUsage.VERTEX | GPUBufferUsage.COPY_DST
    });
    if (!vertex_buffer)
        return;
    device.queue.writeBuffer(vertex_buffer, 0, vertex_data.buffer);
    buffer_layout = { arrayStride: 8, attributes: [{ format: "float32x2", offset: 0, shaderLocation: 0 }] };
    shader_module = device.createShaderModule({ code: shader_code });
    if (shader_module == null)
        throw new Error("Failed to create Shader Module.");
    render_pipeline = device.createRenderPipeline({
        layout: "auto", primitive: { topology: "triangle-strip", stripIndexFormat: "uint32", frontFace: "ccw", cullMode: "back" },
        vertex: { module: shader_module, entryPoint: "vertexMain", buffers: [buffer_layout] },
        fragment: { module: shader_module, entryPoint: "fragmentMain", targets: [{ format: canvas_format }] }
    });
    renderpass_encoder.setPipeline(render_pipeline);
    renderpass_encoder.setVertexBuffer(0, vertex_buffer);
    renderpass_encoder.draw(3);
    renderpass_encoder.end();
    device.queue.submit([encoder.finish()]);
    console.log("Done.");
    return;
}
main();
//# sourceMappingURL=index.js.map