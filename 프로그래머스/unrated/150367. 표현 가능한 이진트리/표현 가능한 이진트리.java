import java.util.*;

class Solution {
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];
        for(int i=0;i<numbers.length;i++){            
            answer[i] = getAnswer(numbers[i]);
        }
        return answer;
    }
    
    int getAnswer(long num){
        char[] binaryChar = toChar(num);
        if(binaryChar[binaryChar.length/2] == '1' && check(binaryChar, true))
            return 1;
        return 0;            
    }
    
    boolean check(char[] binaryChar, boolean prev){
        int mid = binaryChar.length/2;
        if(binaryChar.length == 0){
            return true;
        }
        boolean root = (binaryChar[mid] == '1');
        if(root && !prev)
            return false;
        return check(Arrays.copyOfRange(binaryChar,0,mid), root) && check(Arrays.copyOfRange(binaryChar,mid+1,binaryChar.length), root);
    }
    
    char[] toChar(long num){
        String binaryString = Long.toBinaryString(num);
        int len = getLen(binaryString);
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<len - binaryString.length();i++){
            sb.append("0");
        }
        sb.append(binaryString);
        // System.out.println(sb);
        return sb.toString().toCharArray();
    }
    
    int getLen(String binaryString){
        return (int)Math.pow(2, (int)(Math.log10(binaryString.length()) / Math.log10(2))+1)-1;
    }
    
}