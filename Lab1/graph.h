// Graph class.
class Graph {

 private:
  Graph(const Graph&) {}            // Protect copy constructor
  void operator =(const Graph&) {}  // Protect assignment

 public:
  Graph() {}                        // default constructor
  void init(int n);                 // initialize with num vertices
  int  num_vertices();              // number of verticies
  int  num_edges();                 // number of edges
  void insert_edge(int v1, int v2); // insert directed edge v1 -> v2
  void list_all_edges();            // list all edges in graph
  void list_all_neighbors(int v);   // lists  neighbors of a vertex
  void no_incoming();               // list vertices with no in-edges
};