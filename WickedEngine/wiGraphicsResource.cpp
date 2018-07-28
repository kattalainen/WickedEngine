#include "wiGraphicsResource.h"
#include "Include_DX11.h"
#include "Include_DX12.h"
#include "Include_Vulkan.h"

namespace wiGraphicsTypes
{
	VertexShader::VertexShader()
	{
		SAFE_INIT(resource_DX11);
	}
	VertexShader::~VertexShader()
	{
		SAFE_RELEASE(resource_DX11);
	}

	PixelShader::PixelShader()
	{
		SAFE_INIT(resource_DX11);
	}
	PixelShader::~PixelShader()
	{
		SAFE_RELEASE(resource_DX11);
	}

	GeometryShader::GeometryShader()
	{
		SAFE_INIT(resource_DX11);
	}
	GeometryShader::~GeometryShader()
	{
		SAFE_RELEASE(resource_DX11);
	}

	DomainShader::DomainShader()
	{
		SAFE_INIT(resource_DX11);
	}
	DomainShader::~DomainShader()
	{
		SAFE_RELEASE(resource_DX11);
	}

	HullShader::HullShader()
	{
		SAFE_INIT(resource_DX11);
	}
	HullShader::~HullShader()
	{
		SAFE_RELEASE(resource_DX11);
	}

	ComputeShader::ComputeShader()
	{
		SAFE_INIT(resource_DX11);
	}
	ComputeShader::~ComputeShader()
	{
		SAFE_RELEASE(resource_DX11);
	}

	Sampler::Sampler()
	{
		SAFE_INIT(resource_DX11);
		resource_DX12 = WI_NULL_HANDLE;
		resource_Vulkan = WI_NULL_HANDLE;
	}
	Sampler::~Sampler()
	{
		SAFE_RELEASE(resource_DX11);
	}

	GPUResource::GPUResource()
	{
		SAFE_INIT(SRV_DX11);
		SRV_DX12 = WI_NULL_HANDLE;
		SRV_Vulkan = WI_NULL_HANDLE;
		SAFE_INIT(UAV_DX11);
		UAV_DX12 = WI_NULL_HANDLE;
		UAV_Vulkan = WI_NULL_HANDLE;
		resource_DX12 = WI_NULL_HANDLE;
		resource_Vulkan = WI_NULL_HANDLE;
		resourceMemory_Vulkan = WI_NULL_HANDLE;
	}
	GPUResource::~GPUResource()
	{
		SAFE_RELEASE(SRV_DX11);
		for (auto& x : additionalSRVs_DX11)
		{
			SAFE_RELEASE(x);
		}


		SAFE_RELEASE(UAV_DX11);
		for (auto& x : additionalUAVs_DX11)
		{
			SAFE_RELEASE(x);
		}


	}

	GPUBuffer::GPUBuffer() : GPUResource()
	{
		SAFE_INIT(resource_DX11);
		CBV_DX12 = WI_NULL_HANDLE;
	}
	GPUBuffer::~GPUBuffer()
	{
		SAFE_RELEASE(resource_DX11);
	}

	VertexLayout::VertexLayout()
	{
		SAFE_INIT(resource_DX11);
	}
	VertexLayout::~VertexLayout()
	{
		SAFE_RELEASE(resource_DX11);
	}

	BlendState::BlendState()
	{
		SAFE_INIT(resource_DX11);
	}
	BlendState::~BlendState()
	{
		SAFE_RELEASE(resource_DX11);
	}

	DepthStencilState::DepthStencilState()
	{
		SAFE_INIT(resource_DX11);
	}
	DepthStencilState::~DepthStencilState()
	{
		SAFE_RELEASE(resource_DX11);
	}

	RasterizerState::RasterizerState()
	{
		SAFE_INIT(resource_DX11);
	}
	RasterizerState::~RasterizerState()
	{
		SAFE_RELEASE(resource_DX11);
	}

	VertexShaderInfo::VertexShaderInfo()
	{
		SAFE_INIT(vertexShader);
		SAFE_INIT(vertexLayout);
	}
	VertexShaderInfo::~VertexShaderInfo()
	{
		SAFE_DELETE(vertexShader);
		SAFE_DELETE(vertexLayout);
	}

	Texture::Texture() : GPUResource()
		, independentRTVArraySlices(false), independentRTVCubemapFaces(false), independentSRVArraySlices(false)
		, independentSRVMIPs(false), independentUAVMIPs(false)
	{
		SAFE_INIT(RTV_DX11);
		RTV_DX12 = WI_NULL_HANDLE;
		RTV_Vulkan = WI_NULL_HANDLE;
	}
	Texture::~Texture()
	{
		SAFE_RELEASE(RTV_DX11);
		for (auto& x : additionalRTVs_DX11)
		{
			SAFE_RELEASE(x);
		}

	}
	void Texture::RequestIndependentRenderTargetArraySlices(bool value)
	{
		independentRTVArraySlices = value;
	}
	void Texture::RequestIndependentRenderTargetCubemapFaces(bool value)
	{
		independentRTVCubemapFaces = value;
	}
	void Texture::RequestIndependentShaderResourceArraySlices(bool value)
	{
		independentSRVArraySlices = value;
	}
	void Texture::RequestIndependentShaderResourcesForMIPs(bool value)
	{
		independentSRVMIPs = value;
	}
	void Texture::RequestIndependentUnorderedAccessResourcesForMIPs(bool value)
	{
		independentUAVMIPs = value;
	}

	Texture1D::Texture1D() :Texture()
	{
		SAFE_INIT(texture1D_DX11);
	}
	Texture1D::~Texture1D()
	{
		SAFE_RELEASE(texture1D_DX11);
	}

	Texture2D::Texture2D() :Texture()
	{
		SAFE_INIT(texture2D_DX11);
		SAFE_INIT(DSV_DX11);
		DSV_DX12 = WI_NULL_HANDLE;
		DSV_Vulkan = WI_NULL_HANDLE;
	}
	Texture2D::~Texture2D()
	{
		SAFE_RELEASE(texture2D_DX11);
		SAFE_RELEASE(DSV_DX11);
		for (auto& x : additionalDSVs_DX11)
		{
			SAFE_RELEASE(x);
		}

	}

	Texture3D::Texture3D() :Texture()
	{
		SAFE_INIT(texture3D_DX11);
	}
	Texture3D::~Texture3D()
	{
		SAFE_RELEASE(texture3D_DX11);
	}

	GPUQuery::GPUQuery()
	{
		async_frameshift = 0;
	}
	GPUQuery::~GPUQuery()
	{
		for (auto& x : resource_DX11)
		{
			SAFE_RELEASE(x);
		}
	}


	GraphicsPSO::GraphicsPSO()
	{
		pipeline_DX12 = WI_NULL_HANDLE;
		pipeline_Vulkan = WI_NULL_HANDLE;
	}
	GraphicsPSO::~GraphicsPSO()
	{
	}

	ComputePSO::ComputePSO()
	{
		pipeline_DX12 = WI_NULL_HANDLE;
		pipeline_Vulkan = WI_NULL_HANDLE;
	}
	ComputePSO::~ComputePSO()
	{
	}
}
