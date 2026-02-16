"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.checkWebgpuSupport = checkWebgpuSupport;
exports.getGpuDevice = getGpuDevice;
exports.getCanvasContext = getCanvasContext;
exports.getCommandEncoder = getCommandEncoder;
function checkWebgpuSupport() {
    const supported = (navigator.gpu != null);
    if (!supported)
        throw new Error("WebGPU not supported.");
    return supported;
}
async function getGpuDevice() {
    const adapter = await navigator.gpu.requestAdapter({ featureLevel: "compatibility" });
    if (!adapter)
        throw new Error("GPU Adapter not received.");
    const info = adapter.info;
    const device = await adapter.requestDevice();
    if (!device)
        throw new Error("GPU Device not received.");
    return device;
}
function getCanvasContext(id, device) {
    const canvas = document.getElementById(id);
    if (!canvas)
        throw new Error("Couldn't find canvas.");
    const context = canvas.getContext("webgpu");
    if (!context)
        throw new Error("Couldn't obtain WebGPU context for canvas.");
    const canvas_format = navigator.gpu.getPreferredCanvasFormat();
    const context_configuration = {
        device: device,
        format: canvas_format
    };
    context.configure(context_configuration);
    return { context: context, format: canvas_format };
}
function getCommandEncoder(device) {
    const encoder = device.createCommandEncoder();
    if (encoder == null)
        throw new Error("Failed to create Command encoder.");
    return encoder;
}
//# sourceMappingURL=base.js.map