import yaml
import os

def generate_batches(batches):
    n = len(batches)
    res=[]
    for batch in batches:
        print(batch)
        test_case_batch = []
        for case_num in range(1, batch['num_cases']+ 1):
            generator_args = [batch['batch_num'], case_num]
            test_case_batch.append({'generator_args': generator_args})
        res.append({'batched': test_case_batch, 'points': batch['points']})
    return res

def generate_yaml():
    batches = [{"batch_num": 1, "num_cases": 10, "points": 30}, {"batch_num": 2, "num_cases": 10, "points": 70}]
    data = {
        'checker': 'standard',
        'generator': 'gen.cpp',
        'output_prefix_length': 0,
        'test_cases': generate_batches(batches),
    }

    
    yaml_string = yaml.dump(data)

    
    script_directory = os.path.dirname(os.path.abspath(__file__))

    # Specify the file path for the YAML file
    file_path = os.path.join(script_directory, 'init.yml')

    
    with open(file_path, 'w') as file:
        file.write(yaml_string)

    print(f"YAML file generated at {file_path}")

if __name__ == "__main__":
    generate_yaml()
