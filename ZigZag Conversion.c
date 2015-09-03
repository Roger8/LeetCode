/*leet code zigzag conversion 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

先计算一下每一个zig包含的字符个数，实际上是zigSize = nRows + nRows – 2 = 2* nRows -2 
然后一行一行的加s中的特定元素就行。
第一行和最后一行都只需要加一个字符，每一个zig，而且在s中的index间隔是zigSize。
中间每一行需要添加两个字符到结果中去。第一个字符同上；第二个字符和前面添加这个字符在s上的inde相差正好是zigSize – 2*ir。ir是行index。
0	 	 	 	8	 	 	 	16	 	 	 
1	 	 	7	9	 	 	15	17	 	 	 
2	 	6	 	10	 	14	 	18	 	 	 
3	5	 	 	11	13	 	 	19	 	 	 
4	 	 	 	12	 	 	 	20	 	 

先计算所有不在对角线上的，然后处理对角线， 也就是row 在 row >0 && row < numRows 中的
在第row 行中多出的 	位置在 base + zigsize - 2*i
*/

char* convert(char* s, int numRows) {
    int len=0;
    char *tmp=s;
    //strore length of string in len 
    //while(*tmp++ != '\0') len++;
    for(;s[len]!='\0';len++);
   
   //judge special condition , only one row or length of string less than rows 
    if(numRows ==1 || numRows>= len)
        return s;
    int zigsize = numRows*2 -2;
	//
    char *s2 = (char*)malloc(sizeof(char)*(len+1));
    char *s1 =s2;
    for(int i=0;i<numRows;i++){
        int base  = i;
        
        while(base < len){
            // 处理所有不在对角线上的
			*s1++ = *(s+base);
			// 处理对角线上元素
			//
            if(i>0 && i<numRows-1){
                int t = base + zigsize - 2*i;
                if(t< len)
                    *s1++ = *(s+t);
            }
			//每次加上一个折线步长
            base  = base + zigsize;
        }
    }
    *s1++ = '\0';
    return s2;
}

//python version 
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        sz = len(s)
        if numRows ==1 or numRows >= sz:
            return s
        
        zigsz = 2*numRows -2;
        tmp=[]
        s1=''
        for row in range(numRows):
            base  =row
            while(base < sz):
                s1=s1+s[base]
                if row>0 and row < numRows-1:
                    p=base-2*row+zigsz
                    if  p< sz:
                        s1=s1+s[p]
                base = base + zigsz
                
        return s1