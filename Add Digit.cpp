class Solution {
public:
    int sum(int n){
        int s=0;
        while (n != 0) {
        s=s+ n % 10;
        n = n / 10;
    }
    return s;
    }
    int addDigits(int num) {
        while(num>9)
        {
            num=sum(num);
        }
        return num;
    }
};
