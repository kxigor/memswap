import matplotlib.pyplot as plt
from collections import defaultdict

data = defaultdict(list)

file_names = [ ]

for file_name in file_names:
    with open(file_name, 'r') as file:
        lines = file.readlines()
        function_name = lines[0].strip()
        for line in lines[1:]:
            n, time = map(float, line.split())
            data[function_name].append((n, time))

averaged_data = {}
for function_name, values in data.items():
    avg_data = defaultdict(list)
    for n, time in values:
        avg_data[n].append(time)
    averaged_data[function_name] = [(n, sum(times) / len(times)) for n, times in avg_data.items()]

sorted_data = dict(sorted(averaged_data.items()))

for function_name, values in sorted_data.items():
    values.sort(key=lambda x: x[0])
    n_values, time_values = zip(*values)
    plt.plot(n_values, time_values, label=function_name, linewidth=0.5)

plt.xlabel('Block Size (n)')
plt.ylabel('Time (s)')
plt.legend()
plt.title('Comparison of execution time')
plt.savefig( , dpi=300)