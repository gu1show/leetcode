// Link: https://leetcode.com/problems/count-vowels-permutation/
// Runtime: 2 ms
// Memory: 5.8 MB

class Solution {
public:
  int countVowelPermutation(int n) {
    long aGeneral = 1, eGeneral = 1, iGeneral = 1, oGeneral = 1, uGeneral = 1;
    long aTemp = 1, eTemp = 1, iTemp = 1, oTemp = 1, uTemp = 1;

    for (int i = 2; i <= n; i++) {
      aTemp = (eGeneral + iGeneral + uGeneral) % 1000000007;
      eTemp = (aGeneral + iGeneral) % 1000000007;
      iTemp = (eGeneral + oGeneral) % 1000000007;
      oTemp = iGeneral % 1000000007;
      uTemp = (iGeneral + oGeneral) % 1000000007;

      aGeneral = aTemp;
      eGeneral = eTemp;
      iGeneral = iTemp;
      oGeneral = oTemp;
      uGeneral = uTemp;
    }

    return (aGeneral + eGeneral + iGeneral + oGeneral + uGeneral) % 1000000007;
  }
};
