import java.util.*;

class Solution {
    public int[] solution(int[][] edges, int[] target) {
        //Node 배열 생성
        Node[] nodes = new Node[target.length+1];
        for(int i=0;i<target.length;i++){
            nodes[i+1] = new Node(i+1, target[i]);
        }
        
        //부모 자식 연결
        for(int i=0;i<edges.length;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            nodes[x].children.add(nodes[y]);
        }
        
        //리프 노드 생성
        List<Node> leafs = new ArrayList<>();
        for(int i=1;i<nodes.length;i++){
            if(nodes[i].init()){
                leafs.add(nodes[i]);
            }
        }
        
        List<Node> drops = new ArrayList<>();
        Node root = nodes[1];
        while(!isFinishDrop(leafs)){
            Node drop = root.getNextDropLeaf();
            drops.add(drop);
            drop.cnt++;
            if(drop.isOver()){
                return new int[]{-1};
            }
        }
        
        int[] answer = new int[drops.size()];
        for(int i=0;i<answer.length;i++){
            answer[i] = drops.get(i).nextValue();
        }
        System.out.println(Arrays.toString(answer));
        return answer;
    }
    
    boolean isFinishDrop(List<Node> leafs){
        boolean result = true;
        for(Node leaf : leafs){
            result &= leaf.isEnough();
        }
        return result;
    }
    
    //Node
    class Node{
        int index;
        int targetValue;
        int cnt;
        boolean isLeaf = false;
        Node road = null;
        Node next = null;
        List<Node> children;
        
        Node(int index, int targetValue){
            this.index = index;
            this.targetValue = targetValue;
            children = new ArrayList<>();
        }
        
        boolean init(){
            if(children.size() == 0){
                isLeaf = true;
            } else{
                children.sort((o1, o2) -> {
                    return o1.index - o2.index;
                });

                Node tmp = null;
                for(Node child : children){
                    //자식으로 넘기기위한 설정
                    if(this.road == null){
                        this.road = child;
                        tmp = child;
                    } else{
                        tmp.next = child;
                        tmp = tmp.next;
                    }
                }
                tmp.next = road;
            }
            
            return isLeaf;
        }
        
        boolean isEnough(){
            return cnt*3 >= targetValue;
        }
        
        boolean isOver(){
            return cnt > targetValue;
        }
        
        Node getNextDropLeaf(){
            if(isLeaf)
                return this;
            Node tmp = road.getNextDropLeaf();
            road = road.next;
            return tmp;
        }
        
        int nextValue(){
            cnt--;
            int result = Math.max(1, targetValue - 3*cnt);
            targetValue -= result;
            return result;
        }
    }
}