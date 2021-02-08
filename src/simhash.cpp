#include "simhash/simhash.h"

Simhash::Simhash() : extractor(
    "/usr/local/etc/dict-for-simhash/jieba.dict.utf8", 
    "/usr/local/etc/dict-for-simhash/hmm_model.utf8", 
    "/usr/local/etc/dict-for-simhash/idf.utf8", 
    "/usr/local/etc/dict-for-simhash/stop_words.utf8")
{
}

Simhash::~Simhash()
{
}

uint64_t Simhash::compute(const std::string &text)
{
    std::vector<std::pair<std::string, double> > keyword_weight_pairs;
    if (!this->extract(text, keyword_weight_pairs))
    {
        fprintf(stderr, "failed to extract keywords");
        return 0;
    }

    std::vector<std::pair<uint64_t, double> > hashed_weight_pairs;
    hashed_weight_pairs.resize(keyword_weight_pairs.size());
    for (size_t i = 0; i < hashed_weight_pairs.size(); i++)
    {
        hashed_weight_pairs[i].first = this->hash(keyword_weight_pairs[i].first.c_str(), keyword_weight_pairs[i].first.size());
        hashed_weight_pairs[i].second = keyword_weight_pairs[i].second;
    }

    std::vector<double> weights(64, 0.0);
    const uint64_t u64_1(1);
    for (size_t i = 0; i < hashed_weight_pairs.size(); i++)
    {
        for (size_t j = 0; j < 64; j++)
        {
            weights[j] += (((u64_1 << j) & hashed_weight_pairs[i].first) ? 1 : -1) * hashed_weight_pairs[i].second;
        }
    }

    uint64_t v64 = 0;
    for (size_t i = 0; i < 64; i++)
    {
        if (weights[i] > 0.0)
        {
            v64 |= (u64_1 << i);
        }
    }

    return v64;
}

bool Simhash::extract(const std::string &text, std::vector<std::pair<std::string, double> > &keyword_weight_pairs)
{
    return this->extractor.extract(text, keyword_weight_pairs, 5);
}

uint64_t Simhash::hash(const char* key, size_t len)
{
    return hashlittle(key, len, 0xbc9f1d34);
}

bool Simhash::is_similar(uint64_t doc_a_hs, uint64_t doc_b_hs, uint8_t n)
{
    uint8_t cnt = 0;

    doc_a_hs ^= doc_b_hs;

#if defined(__GNUC__) ||  defined(__clang__)
    cnt = __builtin_popcountll(doc_a_hs);
#else
    while (doc_a_hs && cnt <= n)
    {
        doc_a_hs &= doc_a_hs - 1;
        cnt++;
    }
#endif

    return cnt <= n;
}

std::string Simhash::uint64_to_bin_str(uint64_t src)
{
    std::string dst;
    dst.resize(64);
    for (signed i = 63; i >= 0; i--)
    {
        src & 1 ? dst[i] = '1' : dst[i] = '0';
        src >>= 1;
    }
    return dst;
}

uint64_t Simhash::bin_str_to_uint64(const std::string &src)
{
    uint64_t dst = 0;
    for (signed i = 0; i < 64; i++)
    {
        dst <<= 1;
        if(src[i] == '1')
        {
            dst += 1;
        }
    }
    return dst;
}
