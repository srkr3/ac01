from heapq import heappush, heappop
from collections import defaultdict, Counter

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(text):
    frequency = Counter(text)
    priority_queue = [HuffmanNode(char, freq) for char, freq in frequency.items()]
    while len(priority_queue) > 1:
        left = heappop(priority_queue)
        right = heappop(priority_queue)
        merged = HuffmanNode(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        heappush(priority_queue, merged)
    return priority_queue[0]

def build_huffman_codes(root, prefix, codes):
    if root:
        if not root.left and not root.right:
            codes[root.char] = prefix
        build_huffman_codes(root.left, prefix + "0", codes)
        build_huffman_codes(root.right, prefix + "1", codes)

def huffman_encoding(text):
    if not text:
        return "", None
    root = build_huffman_tree(text)
    codes = {}
    build_huffman_codes(root, "", codes)
    encoded_text = "".join(codes[char] for char in text)
    return encoded_text, root

def huffman_decoding(encoded_text, root):
    if not encoded_text:
        return ""
    decoded_text = ""
    current = root
    for bit in encoded_text:
        if bit == "0":
            current = current.left
        else:
            current = current.right
        if not current.left and not current.right:
            decoded_text += current.char
            current = root
    return decoded_text

# Example usage:
text = "hello world"
encoded_text, tree = huffman_encoding(text)
print("Encoded text:", encoded_text)
decoded_text = huffman_decoding(encoded_text, tree)
print("Decoded text:", decoded_text)
