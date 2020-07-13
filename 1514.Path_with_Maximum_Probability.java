class Edge {
    private int from;
    private int to;
    private double weight;
    public Edge(int from, int to, double weight){
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
    public int getFrom(){return this.from;}
    public int getTo(){return this.to;}
    public double getWeight(){return this.weight;}
    public void show(){
        //for debugging
        System.out.println("From: "+this.from+" To: "+this.to+" Weight: "+this.weight);
    }
}

class dijkstraCouple implements Comparable<dijkstraCouple>{
    private Double distance;
    private int id;
    public dijkstraCouple(int id, double distance){
        this.id = id;
        this.distance = distance;
    }
    public double getDistance(){return this.distance;}
    public int getId(){return this.id;}
    public int compareTo(dijkstraCouple e){
        return this.distance.compareTo(e.getDistance());
    }
}
class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {    
        Map<Integer, List<Edge>> graph = new HashMap<Integer, List<Edge>>();
        double d[] = new double[n];
        boolean visited[] = new boolean[n];
        int m = edges.length;
        //init
        for(int i = 0; i < n; i++){
            graph.put(i, new ArrayList<Edge>());
        }
        for(int i = 0; i < m; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double w = succProb[i];
            w = -Math.log(w);
            Edge e1 = new Edge(a, b, w);
            Edge e2 = new Edge(b, a, w);
            graph.get(a).add(e1);
            graph.get(b).add(e2);
        }
        Arrays.fill(d, 1e300);
        Arrays.fill(visited, false);
        //implementation of djkstra algorithm(lazzy version)
        Queue<dijkstraCouple> pq = new PriorityQueue<dijkstraCouple>();
        d[start] = 0;
        dijkstraCouple s = new dijkstraCouple(start, d[start]);
        pq.offer(s);
        while(!pq.isEmpty()){
            dijkstraCouple top = pq.poll();
            int id = top.getId();
            double dist = top.getDistance();
            visited[id] = true;
            List<Edge> neighbors = graph.get(id);
            for(Edge e : neighbors){
                int to = e.getTo();
                if(!visited[to]){
                    double cost = e.getWeight();
                    double newD = d[id]+cost;
                    if(newD < d[to]){
                        d[to] = newD;
                        pq.offer(new dijkstraCouple(to, newD));
                    }
                }
            }
            
        }
        double res = 1/Math.exp(d[end]);
        return res;
    }
}
