
export function checkWebgpuSupport(): boolean {
	const supported: boolean = (navigator.gpu != null);
	if (! supported) throw new Error("WebGPU not supported.");
	return supported; }

export async function getGpuDevice(): Promise<GPUDevice> {
	const adapter: GPUAdapter | null = await navigator.gpu.requestAdapter({ featureLevel: "compatibility" });
	if (! adapter) throw new Error("GPU Adapter not received.");
	const info: GPUAdapterInfo | null = adapter.info;
	const device: GPUDevice | null = await adapter.requestDevice()
	if (! device) throw new Error("GPU Device not received.");
	return device; }

export function getCanvasContext(id: string, device: GPUDevice): { context: GPUCanvasContext | null, format: GPUTextureFormat } {
	const canvas: HTMLCanvasElement | null = document.getElementById(id) as HTMLCanvasElement;
	if (! canvas) throw new Error("Couldn't find canvas.");
	const context: GPUCanvasContext | null = canvas.getContext("webgpu");
	if (! context) throw new Error("Couldn't obtain WebGPU context for canvas.");
	const canvas_format: GPUTextureFormat = navigator.gpu.getPreferredCanvasFormat();
	const context_configuration: GPUCanvasConfiguration = {
		device: device,
		format: canvas_format };
	context.configure(context_configuration);
	return { context: context, format: canvas_format }; }

export function getCommandEncoder(device: GPUDevice): GPUCommandEncoder | null {
	const encoder: GPUCommandEncoder = device.createCommandEncoder();
	if (encoder == null) throw new Error("Failed to create Command encoder.");
	return encoder; }
