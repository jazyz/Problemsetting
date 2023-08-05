import os
import subprocess
import random


def compile_cpp(filename):
    try:
        file_directory = os.path.dirname(os.path.abspath(__file__))
        subprocess.check_call(
            ["g++", filename, "-o", os.path.splitext(filename)[0]], cwd=file_directory
        )
    except subprocess.CalledProcessError:
        print(f"Compilation of {filename} failed.")
        return False
    return True


def gen_random_array(length, lo=-(10**9), hi=10**9):
    a = [0] * n
    for i in range(n):
        a[i] = random.randint(lo,hi)
    return a


def gen_random_permutation(length):
    p = [0] * n
    for i in range(n):
        p[i] = i + 1
    random.shuffle(p)
    return p


def run_cpp(filename, input_str):
    try:
        file_directory = os.path.dirname(os.path.abspath(__file__))
        process = subprocess.Popen(
            [os.path.join(file_directory, os.path.splitext(filename)[0])],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            cwd=file_directory,
        )

        output, error = process.communicate(input=input_str)

        return output.strip()
    except subprocess.CalledProcessError:
        print(f"Execution of {filename} failed.")
        return None


def compare_outputs(output1, output2):
    if output1 == output2:
        print("Outputs match")
    else:
        print("Outputs differ")
        print(output1)
        print(output2)


if __name__ == "__main__":
    fast_solution = "fast.cpp"
    slow_solution = "slow.cpp"

    if compile_cpp(fast_solution) and compile_cpp(slow_solution):
        while True:
            # Gen data
            n = 10
            arr = gen_random_permutation(n)

            # Set input string
            input_str = f"{n}\n"
            input_str += " ".join(map(str, arr))

            fast_output = run_cpp(fast_solution, input_str)
            slow_output = run_cpp(slow_solution, input_str)

            print(input_str)
            compare_outputs(fast_output, slow_output)

            if fast_output != slow_output:
                break
