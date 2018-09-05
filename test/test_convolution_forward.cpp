#include "test_convolution_forward.hpp"
#include "utils/csv/csv_integration.hpp"

TEST(convolution_fwd, func_check_zero_padding) {
    Desc inputDesc(1, 3, 224, 224);
    Desc filterDesc(21, 3, 3, 3);
    int pad[2] = {0, 0};    // zero padding
    int stride[2] = {1, 1}; // stride 1
    Desc outputDesc =
        calculateConv2DOutputDesc(inputDesc, filterDesc, pad, stride);
    Memory<float> srcData = createMemory<float>(inputDesc);
    Memory<float> dstDataCPU = createMemory<float>(outputDesc);
    Memory<float> dstDataGPU = createMemory<float>(outputDesc);
    Memory<float> filterData = createMemory<float>(filterDesc);
    populateMemoryRandom<float>(srcData);
    populateMemoryRandom<float>(filterData);
    test_convolution_sizes_t testConvolutionSizes(
        inputDesc.N, 1, inputDesc.C, inputDesc.H, inputDesc.W, outputDesc.C,
        outputDesc.H, outputDesc.W, filterDesc.H, filterDesc.W, pad[0], pad[1],
        stride[0], stride[1], 1, 1);

    compute_hipdnn_conv_fwd<float>(testConvolutionSizes, srcData.gpu(),
                                   filterData.gpu(), NULL, dstDataGPU.gpu());

    std::string strt = "./result_unittest.csv";
    std::string testname = "func_check_zero_padding";
    float* temp = dstDataGPU.getDataFromGPU();
    std::string str  = convert_to_string((float*)temp,(int)dstDataGPU.get_num_elements());
    write_to_csv(strt, str, testname);
}

TEST(convolution_fwd, func_check_two_strides) {
    Desc inputDesc(1, 3, 224, 224);
    Desc filterDesc(21, 3, 3, 3);
    int pad[2] = {0, 0};    // zero padding
    int stride[2] = {2, 2}; // stride 1
    Desc outputDesc =
        calculateConv2DOutputDesc(inputDesc, filterDesc, pad, stride);
    Memory<float> srcData = createMemory<float>(inputDesc);
    Memory<float> dstDataCPU = createMemory<float>(outputDesc);
    Memory<float> dstDataGPU = createMemory<float>(outputDesc);
    Memory<float> filterData = createMemory<float>(filterDesc);
    populateMemoryRandom<float>(srcData);
    populateMemoryRandom<float>(filterData);
    test_convolution_sizes_t testConvolutionSizes(
        inputDesc.N, 1, inputDesc.C, inputDesc.H, inputDesc.W, outputDesc.C,
        outputDesc.H, outputDesc.W, filterDesc.H, filterDesc.W, pad[0], pad[1],
        stride[0], stride[1], 1, 1);

    compute_hipdnn_conv_fwd<float>(testConvolutionSizes, srcData.gpu(),
                                   filterData.gpu(), NULL, dstDataGPU.gpu());

    std::string strt = "./result_unittest.csv";
    std::string testname = "func_check_two_strides";
    float* temp = dstDataGPU.getDataFromGPU();
    std::string str  = convert_to_string((float*)temp,(int)dstDataGPU.get_num_elements());
    write_to_csv(strt, str, testname);
}

TEST(convolution_fwd, func_check_padding_and_strides) {
    Desc inputDesc(1, 3, 224, 224);
    Desc filterDesc(21, 3, 3, 3);
    int pad[2] = {2, 2};    // zero padding
    int stride[2] = {2, 2}; // stride 1
    Desc outputDesc =
        calculateConv2DOutputDesc(inputDesc, filterDesc, pad, stride);
    Memory<float> srcData = createMemory<float>(inputDesc);
    Memory<float> dstDataCPU = createMemory<float>(outputDesc);
    Memory<float> dstDataGPU = createMemory<float>(outputDesc);
    Memory<float> filterData = createMemory<float>(filterDesc);
    populateMemoryRandom<float>(srcData);
    populateMemoryRandom<float>(filterData);
    test_convolution_sizes_t testConvolutionSizes(
        inputDesc.N, 1, inputDesc.C, inputDesc.H, inputDesc.W, outputDesc.C,
        outputDesc.H, outputDesc.W, filterDesc.H, filterDesc.W, pad[0], pad[1],
        stride[0], stride[1], 1, 1);

    compute_hipdnn_conv_fwd<float>(testConvolutionSizes, srcData.gpu(),
                                   filterData.gpu(), NULL, dstDataGPU.gpu());

    std::string strt = "./result_unittest.csv";
    std::string testname = "func_check_padding_and_stride";
    float* temp = dstDataGPU.getDataFromGPU();
    std::string str  = convert_to_string((float*)temp,(int)dstDataGPU.get_num_elements());
    write_to_csv(strt, str, testname);
}
