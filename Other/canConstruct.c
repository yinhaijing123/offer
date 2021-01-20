/*给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)*/
// bool canConstruct(char * ransomNote, char * magazine){
//     if(ransomNote==NULL||*ransomNote=='\0')
//         return true;
//     int magSz=strlen(magazine);
//     int ranSz=strlen(ransomNote);
//     if(magSz<ranSz)
//         return false;
//     int start=0;
//     int end=start;
//     while(start<magSz-1)
//     {
//         if(ransomNote[0]==magazine[start++])
//         {   
//             end=start;
//             int i=0; 
//             for(i=1;i<ranSz;++i)
//             {
//                 if(ransomNote[i]!=magazine[end++])
//                 {
//                     end=start;
//                     break;
//                 }
//             }
//             if(i==ranSz)
//                 return true;
//         }
//     }
//     return false;
// }

bool canConstruct(char * ransomNote, char * magazine){
    if(ransomNote==NULL||*ransomNote=='\0')
        return true;
    //1.统计magazine中各字符的个数
    int magcharnum[26];
    memset(magcharnum,0,26*sizeof(int));

    //2.统计magazine中包含的字符个数
    int i;
    for(i=0;i<strlen(magazine);++i)
    {
        ++magcharnum[magazine[i]-'a'];
    }
    //3.遍历ransomNote，判断magazine中是否有ransomNote中的所有字符以及重复的字符是否个数够量
    for(i=0;i<strlen(ransomNote);++i)
    {
        if(magcharnum[ransomNote[i]-'a']==0)
            return false;
        else
            --magcharnum[ransomNote[i]-'a'];
    }
    return true;
}