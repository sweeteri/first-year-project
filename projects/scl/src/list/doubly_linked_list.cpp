#include <iostream>

#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;

template <typename T> DoublyLinkedList<T>::DoublyLinkedList::~DoublyLinkedList() noexcept {
    while (begin) {
        auto* item_to_delete = begin;
        begin = begin->next;
        delete item_to_delete;
    }
}
template <typename T> void DoublyLinkedList<T>::DoublyLinkedList::push_back(const T& value) noexcept {
    auto* new_node = new Node(value);
    if (begin == nullptr) {
        begin = new_node;
        end = new_node;
    } else {
        end->next = new_node;
        new_node->prev = end;
        end = new_node;
    }
}

template <typename T> bool DoublyLinkedList<T>::DoublyLinkedList::has_item(const T& value) const noexcept {
    auto* current = begin;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T> void DoublyLinkedList<T>::DoublyLinkedList::print() const noexcept {
    auto* current = begin;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T> bool DoublyLinkedList<T>::DoublyLinkedList::remove_first(const T& value) noexcept {
    auto* current = begin;
    while (current != nullptr) {
    if (current->value == value) {
        if (current == begin) {
            begin = current->next;
        } else {
            current->prev->next = current->next;
        }
        if (current == end) {
            end = current->prev;
        } else {
            current->next->prev = current->prev;
        }
        delete current;
        return true;
    }
    current = current->next;
    }
    return false;
}

template <typename T> int DoublyLinkedList<T>::DoublyLinkedList::size() const noexcept {
    auto* current = begin;
    std::size_t size = 0;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}
