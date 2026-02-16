export declare function checkWebgpuSupport(): boolean;
export declare function getGpuDevice(): Promise<GPUDevice>;
export declare function getCanvasContext(id: string, device: GPUDevice): {
    context: GPUCanvasContext | null;
    format: GPUTextureFormat;
};
export declare function getCommandEncoder(device: GPUDevice): GPUCommandEncoder | null;
//# sourceMappingURL=base.d.ts.map