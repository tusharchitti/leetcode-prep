class Solution {
public:
    // int sti(string input)
    // {
    //     return stoi(input);
    // }

    // int getLower(string input)
    // { 
    //     int len = input.length();
    //     int ans =INT_MAX;
    //     string ansString = "";
    //     if(len%2 == 0)
    //     {
    //         int left = sti(reverse(input.substr(0, len/2)));
    //         int right = sti(input.substr(len/2, len/2));
    //         if(left>=right) {
    //         string option = input.substr(0, len/2)+reverse(input.substr(0, len/2));
    //         if(abs(sti(option)-sti(input))< abs(sti(option)-sti(ans)))
    //         {
    //             ans = sti(option);
    //             ansString = option;
    //         }
    //         }
    //         else
    //         {
    //             int num = sti(input.substr(0, len/2));
    //             num++;
    //             string nti = to_string(num);
    //             string option2 = nti.substr(0, nti.length()/2)+reverse(nti.substr(0, nti.length()/2));   
    //             if(abs(sti(option2)-sti(input))< abs(sti(option2)-sti(ans)))
    //             {
    //                 ans = sti(option2);
    //                 ansString = option2;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         // now its odd
    //               int left = sti(reverse(input.substr(0, len/2)));
    //               int right = sti(input.substr(len/2+1, len/2));
    //               if(left>=right)
    //               {
    //                 string option = input.substr(0, len/2)+input[len/2]+reverse(input.substr(0, len/2));
    //                 if(abs(sti(option)-sti(input))< abs(sti(option)-sti(ans)))
    //                 {
    //                     ans = sti(option);
    //                     ansString = option;
    //                 }
    //               }
    //               else
    //               {

    //               }
    //               }
    //     }

    // }

    // int reverse(string n)
    // {
    //     std::reverse(n.begin(), n.end());
    //     return n;
    // }
     
    string nearestPalindromic(string n) {
         int len = n.size();
    long originalNum = std::stol(n);
    
    // Generate potential candidates
    std::vector<long> candidates;
    candidates.push_back((long)pow(10, len - 1) - 1); // Smaller edge case: 999...
    candidates.push_back((long)pow(10, len) + 1);     // Larger edge case: 100...01
    
    // Use the left half to generate potential palindromes
    long prefix = std::stol(n.substr(0, (len + 1) / 2));
    for (int i = -1; i <= 1; ++i) {
        std::string p = std::to_string(prefix + i);
        std::string pal = p + std::string(p.rbegin() + (len % 2), p.rend());
        candidates.push_back(std::stol(pal));
    }

    // Find the closest palindrome
    long closest = -1;
    for (long candidate : candidates) {
        if (candidate == originalNum) continue; // Skip the number itself
        if (closest == -1 || 
            std::abs(candidate - originalNum) < std::abs(closest - originalNum) || 
            (std::abs(candidate - originalNum) == std::abs(closest - originalNum) && candidate < closest)) {
            closest = candidate;
        }
    }
    return std::to_string(closest);
    }
}; 