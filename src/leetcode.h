#pragma once

#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    string out(word1.size() + word2.size(), ' ');
    int out_size = 0;

    for (int i = 0; i < max(word1.size(), word2.size()); i++)
    {
        if (i < word1.size())
        {
            out[out_size++] = word1[i];
        }
        if (i < word2.size())
        {
            out[out_size++] = word2[i];
        }
    }

    return out;
}

string gcdOfStrings(string str1, string str2)
{
    int gdc = gcd(str1.size(), str2.size());
    string chunk = str1.substr(0, gdc);
    
    for (auto it = str1.begin(); it != str1.end(); it += gdc) 
    {
        auto i = distance(str1.begin(), it);
        string temp = str1.substr(i, gdc);

        if (temp != chunk) {
            return "";
        }
    }

    for (auto it = str2.begin(); it != str2.end(); it += gdc) 
    {
        auto i = distance(str2.begin(), it);
        string temp = str2.substr(i, gdc);

        if (temp != chunk) {
            return "";
        }
    }

    return chunk;
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    vector<bool> out(candies.size(), false);

    int max = *max_element(candies.begin(), candies.end());

    for (uint8_t i = 0; i < candies.size(); i++)
    {
        out[i] = (candies[i] + extraCandies) >= max;
    }
    
    return out;
}