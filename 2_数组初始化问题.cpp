/*
a[10]={}  //所有为0
a[10]={0} //所有为0
a[10]={5} //{5,0....}

初始化其他值
1.<string.h> memset函数初始化，建议只初始化0，-1，
  功能性不如fill，但执行速度快。
  memset(a,5,size(a))

2.<algorithm> fill(begin,end,value)函数
   fill(a,a+5,7);
*/
