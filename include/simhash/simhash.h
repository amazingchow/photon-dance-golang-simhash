#ifndef __PHOTON_DANCE_SIMHASH_H__
#define __PHOTON_DANCE_SIMHASH_H__

#include <cppjieba/KeywordExtractor.hpp>
#include <jenkins/jenkins.h>

#include <cstdio>
#include <string>

class Simhash final {

public:
    /* 构造函数 */
    Simhash();
    /* 析构函数 */
    ~Simhash();

private:
    /* 拷贝构造 */
    Simhash(const Simhash &) = delete;
    Simhash(Simhash &&) = delete;
    /* 赋值拷贝 */
    Simhash& operator=(const Simhash &) = delete;
    Simhash& operator=(Simhash &&) = delete;

public:
    uint64_t compute(const std::string &text);
    static bool is_similar(uint64_t doc_a_hs, uint64_t doc_b_hs, uint8_t n = 3);
    static std::string uint64_to_bin_str(uint64_t src);
    static uint64_t bin_str_to_uint64(const std::string &src);

private:
    bool extract(const std::string &text, std::vector<std::pair<std::string, double> > &keywords);
    uint64_t hash(const char* key, size_t len);

private:
    CppJieba::KeywordExtractor extractor;
};

#endif /* __PHOTON_DANCE_SIMHASH_H__ */
