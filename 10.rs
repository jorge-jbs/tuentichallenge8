use std::collections::HashSet;
use std::hash::{Hash, Hasher};
use std::cmp::Ordering;

#[derive(Clone, Copy)]
struct Edge {
    a: i32,
    b: i32,
}

impl Hash for Edge {
    fn hash<H>(&self, state: &mut H) where H: Hasher {
        let a = self.sort();
        a.a.hash(state);
        a.b.hash(state);
    }
}

impl Edge {
    fn sort(self) -> Edge {
        Edge {
            a: ::std::cmp::min(self.a, self.b),
            b: ::std::cmp::max(self.a, self.b),
        }
    }
}

impl PartialEq for Edge {
    fn eq(&self, other: &Edge) -> bool {
        let a = self.sort();
        let b = other.sort();
        a.a == b.a && a.b == b.b
    }
}

impl Eq for Edge {}

impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Edge) -> Option<Ordering> {
        let a = self.sort();
        let b = other.sort();
        if a.a != b.a {
            Some(a.b.cmp(&b.b))
        } else {
            Some(a.a.cmp(&a.a))
        }
    }
}

impl Ord for Edge {
    fn cmp(&self, other: &Edge) -> Ordering {
        let a = self.sort();
        let b = other.sort();
        if a.a != b.a {
            a.b.cmp(&b.b)
        } else {
            a.a.cmp(&a.a)
        }
    }
}

#[derive(Clone)]
struct Graph(HashSet<Edge>);

impl PartialEq for Graph {
    fn eq(&self, other: &Graph) -> bool {
        self.0.is_subset(&other.0) && other.0.is_subset(&self.0)
    }
}

impl Eq for Graph {}

impl Hash for Graph {
    fn hash<H>(&self, state: &mut H) where H: Hasher {
        let mut a: Vec<&Edge> = self.0.iter().collect();
        a.sort();
        for s in a.iter() {
            s.hash(state);
        }
    }
}

impl Graph {
    fn new() -> Graph {
        Graph(HashSet::new())
    }
}

fn arrangements(p: i32, argm_memo: &mut Vec<HashSet<Graph>>, argm_vis: &mut [bool; 50]) -> HashSet<Graph> {
    if p % 2 == 1 { return HashSet::new() }
    if argm_vis[(p/2) as usize] { return argm_memo[(p/2) as usize].clone() }
    let mut graphs: HashSet<Graph> = HashSet::new();
    if p == 4 {
        {
            let mut graph: Graph = Graph::new();
            graph.0.insert(Edge { a: 0, b: 1 });
            graph.0.insert(Edge { a: 2, b: 3 });
            graphs.insert(graph);
        }
        {
            let mut graph: Graph = Graph::new();
            graph.0.insert(Edge { a: 0, b: 3 });
            graph.0.insert(Edge { a: 1, b: 2 });
            graphs.insert(graph);
        }
    } else {
        for x in 0..p/2 {
            for mut g in arrangements(p - 2, argm_memo, argm_vis) {
                g = Graph(g.0.iter().map(|e| {
                    Edge {
                        a: (e.a + 2 + x) % p,
                        b: (e.b + 2 + x) % p,
                    }
                }).collect());
                g.0.insert(Edge { a: x, b: x+1 });
                graphs.insert(g);
            }
        }
    }
    argm_vis[(p/2) as usize] = true;
    argm_memo[(p/2) as usize] = graphs.clone();
    graphs
}

fn main() {
    println!("hola");
    let mut argm_memo: Vec<HashSet<Graph>> = vec![HashSet::new(); 50];
    let mut argm_vis: [bool; 50] = [false; 50];

    /*
    for g in arrangements(6) {
        println!("{{");
        for e in g.0 {
            println!("  {} -> {}", e.a, e.b);
        }
        println!("}}");
    }
    */
    for p in 0..13 {
        println!("{}: {}", p*2, arrangements(p*2, &mut argm_memo, &mut argm_vis).len());
    }
    println!("adiós");
}
