class Solution:
    def smallestNumber(self, pattern: str) -> str:
        self.result = []

        # Start building the sequence by calling the helper function
        self.build_sequence(0, 0, pattern)
        # Reverse the final result
        return "".join(self.result[::-1])

    # Recursively build the sequence
    def build_sequence(self, current_index: int, current_count: int, pattern: str) -> int:
        if current_index != len(pattern):
            print(current_index, current_count, pattern[current_index])

            if pattern[current_index] == "I":
                # If 'I', increment the count and move to the next index
                self.build_sequence(current_index + 1, current_index + 1, pattern)
            else:
                # If 'D', keep the count and move to the next index
                current_count = self.build_sequence(current_index + 1, current_count, pattern)

        self.result.append(str(current_count + 1))

        # Return the next count for the sequence
        return current_count + 1


if __name__ == "__main__":
    pattern = "DDD"
    print(Solution().smallestNumber(pattern))

    pattern = "IIIDIDDD"
    print(Solution().smallestNumber(pattern))
