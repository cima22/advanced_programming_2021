#include <iostream>
#include <memory>
#include <utility>
#include <iterator>
#include <algorithm>
#include <vector>

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

  template <typename O>
  class _iterator;

  using iterator = _iterator<T>;
  using const_iterator = _iterator<const T>;

  iterator begin() {return iterator{head.get()};}
  const_iterator begin() const {return const_iterator{head.get()};}

  auto end() noexcept {return iterator{nullptr};}
  auto end() const noexcept {return const_iterator{nullptr};}

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
   for(const auto& el : x)
	os << x << " ";
   os << std::endl;
   return os;
  }
};

template <typename T>
template <typename O>
class List<T>::_iterator{
  using node = typename List<T>::node;
  node* current;
  
  public:
  using value_type = O;
  using reference = value_type&;
  using pointer = value_type*;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  explicit _iterator(node* p):current{p} {}

  reference operator*() const {return current->value;}

  pointer operator->() const {return &**this;}

  //pre-increment
  _iterator& operator++(){
   current = current->next.get();
   return *this;
  }

  //post-increment
  _iterator& operator++(int){
   auto tmp{*this};
   ++(*this);
   return tmp;
  }

  friend bool operator==(_iterator& a, _iterator& b){
   return a.current == b.current;
  }

  friend bool operator!=(_iterator& a, _iterator& b){
   return !(a == b);
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

 for(auto x : l){
  std::cout << x << std::endl;
 }

 std::vector<int> v(3);

 std::copy(l.begin(), l.end(), v.begin());

 for(auto x : v){
  std::cout << x << std::endl;
 }

 return 0;

 List<int> l2{l};

 l.insert(99,Method::push_front);
 l2.insert(877,Method::push_back);


 std::cout << l << "\n" << l2 << std::endl;
}
