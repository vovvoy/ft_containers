#ifndef CONTAINER_LISTNODE_HPP
#define CONTAINER_LISTNODE_HPP

namespace ft {
	template <typename T>
	class node {
	public:
		T			data;
		node*		next;
		node*		prev;

		explicit node(const T &val = T()) : data(val), next(0), prev(0) { }
		node(const node &other) : data(other.data), next(other.next), prev(other.prev) { }
		~node() { }

		node&	operator=(const node& rhs) {
			if (this != &rhs) {
				this->data = rhs.data;
				this->next = rhs.next;
				this->prev = rhs.prev;
			}
			return *this;
		}
		bool	operator==(const node& rhs) const {
			return (this->data == rhs.data && this->next = rhs.next && this->prev == rhs.prev);
		}
		bool	operator!=(const node& rhs) const {
			return *this != rhs;
		}
		node*	getnext() {
			return this->next;
		}
		node*	getprevious() {
			return this->prev;
		}
	};
} // namespace ft

#endif //CONTAINER_LISTNODE_HPP
