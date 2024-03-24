#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iterator>
#include <iostream>
#include <stdexcept>

template<typename T>
class Node {
public:
	T element;
	Node<T>* next;
	Node() : next(nullptr) {}
	Node(T element) : element(element), next(nullptr) {}
};

template<typename T>
class Iterator {
public:
	using iterator_category = std::forward_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;

	Iterator(Node<T>* ptr) : current_(ptr) {}
	Iterator operator++() {
		current_ = current_->next;
		return *this;
	}
	Iterator operator++(int dummy) {
		Iterator temp{current_};
		current_ = current_->next;
		return temp;
	}
	T& operator*() {
		return current_->element;
	}
	bool operator==(const Iterator<T>& iter) {
		return current_ == iter.current_;
	}
	bool operator!=(const Iterator<T>& iter) {
		return current_ != iter.current_;
	}
private:
	Node<T>* current_;
};

template<typename T>
class LinkedList {
public:
	LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
	LinkedList(const LinkedList<T>& list) {
		head_ = nullptr;
		tail_ = nullptr;
		size_ = 0;
		Node<T>* current = list.head_;
		while(current != nullptr) {
			this->add(current->element);
			current = current->next;
		}
	}
	virtual ~LinkedList() {
		clear();
	}
	void add_first(const T& element) {
		Node<T>* new_node = new Node<T>(element);
		new_node->next = head_;
		head_ = new_node;
		++size_;
		if(tail_ == nullptr) {
			tail_ = head_;
		}
	}
	void add_last(const T& element) {
		Node<T>* new_node = new Node<T>(element);
		if(size_ == 0) {
			head_ = new_node;
			tail_ = new_node;
		} else {
			tail_->next = new_node;
			tail_ = new_node;
		}
		++size_;
	}
	T get_first() const {
		if(size_ == 0) {
			throw std::runtime_error("Index out of range");
		} else {
			return head_->element;
		}
	}
	T get_last() const {
		if(size_ == 0) {
			throw std::runtime_error("Index out of range");
		} else {
			return tail_->element;
		}
	}
	T remove_first() {
		if(size_ == 0) {
			throw std::runtime_error("No elements in the list");
		} else {
			Node<T>* temp = head_;
			head_ = head_->next;
			--size_;
			T element = temp->element;
			delete temp;
			return element;
		}
	}
	T remove_last() {
		if(size_ == 0) {
			throw std::runtime_error("No elements in the list");
		} else if(size_ == 1) {
			Node<T>* temp = head_;
			head_ = nullptr;
			tail_ = nullptr;
			size_ = 0;
			T element = temp->element;
			delete temp;
			return element;
		} else {
			Node<T>* current = head_;
			for(int i = 0; i < size_ - 2; ++i) {
				current = current->next;
			}
			Node<T>* temp = tail_;
			tail_ = current;
			tail_->next = nullptr;
			--size_;
			T element = temp->element;
			delete temp;
			return element;
		}
	}
	void add(const T& element) {
		add_last(element);
	}
	void add(const T& element, int index) {
		if(index == 0) {
			add_first(element);
		} else if(index >= size_) {
			add_last(element);
		} else {
			Node<T>* current = head_;
			for(int i = 0; i < index - 1; ++i) {
				current = current->next;
			}
			Node<T>* new_node = new Node<T>(element);
			new_node->next = current->next;
			current->next = new_node;
			++size_;
		}
	}
	void clear() {
		while(head_ != nullptr) {
			Node<T>* temp = head_;
			head_ = head_->next;
			delete temp;
		}
		tail_ = nullptr;
		size_ = 0;
	}
	bool contains(const T& element) const {
		Node<T>* current = head_;
		for(int i = 0; i < size_; ++i) {
			if(current->element == element) {
				return true;
			}
			current = current->next;
		}
		return false;
	}
	T& get(int index) const {
		if(index < 0 || index >= size_) {
			throw std::runtime_error("Index out of range");
		}
		Node<T>* current = head_;
		for(int i = 0; i < index; ++i) {
			current = current->next;
		}
		return current->element;
	}
	int index_of(const T& element) const {
		Node<T>* current = head_;
		for(int i = 0; i < size_; ++i) {
			if(current->element == element) {
				return i;
			}
			current = current->next;
		}
		return -1;
	}
	bool is_empty() const {
		return head_ == nullptr;
	}
	int last_index_of(const T& element) const {
		int last_index = -1;
		Node<T>* current = head_;
		for(int i = 0; i < size_; ++i) {
			if(current->element == element) {
				last_index = i;
			}
			current = current->next;
		}
		return last_index;
	}
	bool remove(const T& element) {
		Node<T>* previous = head_;
		Node<T>* current;

		if(head_ != nullptr) {
			if(element == head_->element) {
				head_ = head_->next;
				--size_;
				return true;
			} else {
				current = head_->next;
			}
		} else {
			return false;
		}

		for(int i = 0; i < size_ - 1; ++i) {
			if(element == current->element) {
				previous->next= current->next;
				--size_;
				return true;
			} else {
				previous = current;
				current = current->next;
			}
		}
		return false;
	}
	int get_size() const {
		return size_;
	}
	T remove_at(int index) {
		if(index < 0 || index >= size_) {
			throw std::runtime_error("Index out of range");
		} else if(index == 0) {
			return remove_first();
		} else if(index == size_ - 1) {
			return remove_last();
		} else {
			Node<T>* previous = head_;
			for(int i = 0; i < index - 1; ++i) {
				previous = previous->next;
			}
			Node<T>* current = previous->next;
			previous->next = current->next;
			--size_;
			T element = current->element;
			delete current;
			return element;
		}
	}
	T& set(const T& element, int index) {
		if(index < 0 || index >= size_) {
			throw std::runtime_error("Index out of range");
		}
		Node<T>* current = head_;
		for(int i = 0; i < index; ++i) {
			current = current->next;
		}
		T old_element = current->element;
		current->element = element;
		return old_element;
	}
	void print_list() {
		for(int i = 0; i < size_; ++i) {
			std::cout << this->get(i) << " ";
		}
		std::cout << "\n";
	
	}
	Iterator<T> begin() const {
		return Iterator<T>(head_);
	}
	Iterator<T> end() const {
		return Iterator<T>(tail_->next);
	}
private:
	int size_;
	Node<T>* head_;
	Node<T>* tail_;
};

#endif // LINKED_LIST_H
