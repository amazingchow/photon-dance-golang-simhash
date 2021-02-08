#include <cstdio>
#include <string>

#include <simhash/simhash.h>

int main(int argc, char** argv)
{
    std::string text("做一件事，无论大小，倘无恒心，是很不好的。而看一切太难，固然能使人无成，但若看得太容易，也能使事情无结果。");

    Simhash sim;
    uint64_t v = sim.compute(text);
    printf("文本: %s\n", text.c_str());
    std::string v_str = Simhash::uint64_to_bin_str(v);
    printf("二进制表达: %s\n\n", v_str.c_str());

    std::string b1("0000000000000010000000000000000001111011011101000100001111100001");
    printf("文本A的二进制表达: %s\n", b1.c_str());
    uint64_t u1 = Simhash::bin_str_to_uint64(b1);
    std::string b2("0000000000000000000000000000000001111011010101000100001111100001");
    printf("文本B的二进制表达: %s\n", b2.c_str());
    uint64_t u2 = Simhash::bin_str_to_uint64(b2); 
    
    if (Simhash::is_similar(u1, u2))
    {
        printf("经过Simhash计算判断可知两文档相似\n\n");
    }
    else
    {
        printf("经过Simhash计算判断可知两文档不相似\n\n");
    }

    std::string b3("0000000000000010000000000000000001111011011101000100001111100001");
    printf("文本A的二进制表达: %s\n", b3.c_str());
    uint64_t u3 = Simhash::bin_str_to_uint64(b3);
    std::string b4("0010000000001000000000000000000001111011010101000100101101100001");
    printf("文本B的二进制表达: %s\n", b4.c_str());
    uint64_t u4 = Simhash::bin_str_to_uint64(b4); 
    
    if (Simhash::is_similar(u3, u4))
    {
        printf("经过Simhash计算判断可知两文档相似\n\n");
    }
    else
    {
        printf("经过Simhash计算判断可知两文档不相似\n\n");
    }

    return 0;
}
