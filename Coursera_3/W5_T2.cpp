#include <algorithm>
#include <vector>

using namespace std;

template <typename Token>
using Sentence = vector<Token>;

template <typename TokenForwardIt>
TokenForwardIt FindSentenceEnd(TokenForwardIt tokens_begin, TokenForwardIt tokens_end) 
{
    const TokenForwardIt before_sentence_end = adjacent_find(tokens_begin, tokens_end,
                                                [](const auto& left_token, const auto& right_token) 
                                                {
                                                    return left_token.IsEndSentencePunctuation()
                                                        && !right_token.IsEndSentencePunctuation();
                                                });
    return before_sentence_end == tokens_end
        ? tokens_end
        : next(before_sentence_end);
}

template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
    vector<Sentence<Token>> sentences;
    auto tokens_begin = begin(tokens);
    const auto tokens_end = end(tokens);
    while (tokens_begin != tokens_end) 
    {
        const auto sentence_end = FindSentenceEnd(tokens_begin, tokens_end);
        Sentence<Token> sentence;
        for (; tokens_begin != sentence_end; ++tokens_begin) 
        {
            sentence.push_back(move(*tokens_begin));
        }
        sentences.push_back(move(sentence));
    }
    return sentences;
}