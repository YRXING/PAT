/*
a[10]={}  //����Ϊ0
a[10]={0} //����Ϊ0
a[10]={5} //{5,0....}

��ʼ������ֵ
1.<string.h> memset������ʼ��������ֻ��ʼ��0��-1��
  �����Բ���fill����ִ���ٶȿ졣
  memset(a,5,size(a))

2.<algorithm> fill(begin,end,value)����
   fill(a,a+5,7);
*/
