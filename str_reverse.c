//string reverse
//http://stackoverflow.com/questions/198199/how-do-you-reverse-a-string-in-place-in-c-or-c

/ 补充
int main()
{
    char a[] = "Hello world"; /* the literal string is copied into a local array which is destroyed after that array goes out of scope */

    char* p = "Hello world"; /* the literal string is copied in the read-only section of memory (any attempt to modify it is an undefined behavior) */
}
/*---------------------------------------------*/
//第一种
char* reversestr(char* s){
	int i;
	for(i =0;s[i]!='\0';i++);
	
	/*int p=0,q=i-1;
	for( ;p<q;p++,--q){
		char tmp = *(s+p);
		*(s+p) = *(s+q);
		*(s+q) = tmp;
	}*/
	char * s1=s;
	char * end = s+i-1;
	while(s<end){
		unsigned int tmp = *s;
		*s = *end;
		*end = tmp;
		s++;
		end--;
	}
	return s1;
}

void revstr(char* s){
	//这里的s是临时变量，s也指向"hello world"
	//改变s 对 p 没有影响，所以可以进行s++
	int len=0;
	while(s[len]!='\0') len++;

	char * end =s ;
	while(*end != '\0') end++;
	end--;
	while(s<end){
		char tmp = *s;
		*s = *end;
		*end = tmp;
		s++;
		end--;
	}
}
//第二种
void strrev(char *p)
{
  char *q = p;
  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,  //注意这里是逗号
    *q = *p ^ *q,
    *p = *p ^ *q;
}

int main(){

	char p[] ="hello world";// 声明为字符数组的才可以使用*p操作，
	char *s1 ="hello world";//字符串在静态区，使用*p 非法
	char *d =p;

	printf(p);
	printf(" \n");
	revstr(p);
	printf(p);
	printf(reversestr(p));
}