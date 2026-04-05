class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        k=0
        l=0
        for i in moves:
            if(i=='U'):
                k+=1
            elif(i=='D'):
                k-=1
            elif(i=='L'):
                l+=1
            else:
                l-=1
        if((k==0) and (l==0)):
            return 1>0
        return 1<0