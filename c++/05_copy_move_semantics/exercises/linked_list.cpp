#include <iostream>
#include <utility>
#include <memory>

enum class Insertion_method { push_back, push_front };

template <typename T>
class List {
 public:
  using value_type = T;

  void insert(const value_type& v, const Insertion_method m);

  std::size_t size() const;

  void reset();

 List() : _size{},head{nullptr}{} // default ctor

 private:
  
  struct node {
   value_type value;
   std::unique_ptr<node> next;

   node() : value{},next{nullptr} {} // default ctor

   node(const value_type& value) : value{value},next{nullptr} {}
  };

  std::unique_ptr<node> head;
  std::size_t _size;

  void push_back(const value_type& v);

  void push_front(const value_type& v);
};

void List::push_back(const value_type& v){
 auto& n = head;
 for(; n; n = n.next)
}
