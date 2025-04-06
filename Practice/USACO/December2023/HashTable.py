class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = Nones


class HashTable:
    def __init__(self, initial_size=50):
        self.size = initial_size
        self.table = [None] * initial_size

    def hash_function(self, key):
        return hash(key) % self.size

    def set_val(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None:
            self.table[index] = Node(key, value)
        else:
            current = self.table[index]
            while current.next:
                if current.key == key:
                    current.value = value
                    return
                current = current.next
            current.next = Node(key, value)

    def get_val(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        return "No record found"

    def delete_val(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        if current and current.key == key:
            self.table[index] = current.next
            return
        while current and current.next:
            if current.next.key == key:
                current.next = current.next.next
                return
            current = current.next

    def __str__(self):
        result = []
        for node in self.table:
            while node:
                result.append(f"({node.key}, {node.value})")
                node = node.next
        return "".join(result)


# Example usage:
hash_table = HashTable()
hash_table.set_val('gfg@example.com', 'some value')
print(hash_table)

hash_table.set_val('portal@example.com', 'some other value')
print(hash_table)

print(hash_table.get_val('portal@example.com'))

hash_table.delete_val('portal@example.com')
print(hash_table)
