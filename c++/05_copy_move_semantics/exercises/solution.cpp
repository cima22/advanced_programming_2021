#include <iostream>
#include <memory>
#include <utility>

enum class Method{push_back, push_front};

template <typename T>
class List{
 
 struct node{
  std::unique_ptr<node> next;
  T value;
  explicit node(const T& x): value{x} {}
  node(const T& x, node* p): next{p}, value{x} {}
  explicit node(const std::unique_ptr<node>& x): value{x -> value}{
   if(x->next) 
	next.reset(new node(x->next));
  }
 };

 std::unique_ptr<node> head;
 std::size_t _size;

 void push_front(const T& x){
  auto tmp = new node{x, head.release()}; // head releases the ownership of the first node and gives the raw pointer to the new first node that we are pushing in front
  head.reset(tmp); // now head owns tmp, the new first node
  // head.reset(new node{x, head.release()})
 }

 void push_back(const T& x){
  auto tmp = head.get();
  if(!tmp){ // our list is empty
   head.reset(new node{x});
   return;
  }

  while(tmp -> next)
   tmp = tmp -> next.get();
 
  tmp -> next.reset(new node{x});
 }

 public:
  List() = default;

  // move semantics
   List(List&& x): head{std::move(x.head)}, _size{std::move(x._size)} {}
   List& operator=(List&&) = default;
 
  // copy semantics
   List(const List& x): _size{x._size}{
    if(x.head)
	head.reset(new node{x.head});
   }

   List& operator=(const List& x){
    head.reset(); // release the memory
    auto tmp = x; // copy ctor
    *this = std::move(tmp); // move assignment
    return *this;
   }

  void insert(const T& x, const Method m);

  friend
  std::ostream& operator<<(std::ostream& os, const List& x){
   auto tmp = x.head.get();
   os << "[" << x._size << "] ";
   while(tmp){
    os << tmp->value << " ";
    tmp = tmp->next.get();
   }
   os << std::endl;
   return os;
  }
};

template <typename T>
void List<T>::insert(const T& x, const Method m){
 switch(m){
  case Method::push_back:
	  push_back(x);
	  break;
  case Method::push_front:
	  push_front(x);
	  break;
  default:
   std::cerr << "unknown method" << std::endl;
   break;
	
 };
 ++_size;
}

int main(){
 List<int> l{};

 l.insert(3,Method::push_back);
 l.insert(1,Method::push_back);
 l.insert(5,Method::push_front);

 List<int> l2{l};

 l.insert(99,Method::push_front);
 l2.insert(877,Method::push_back);


 std::cout << l << "\n" << l2 << std::endl;
}
