```c++

const int kSize = 2500;

const int kIterationsCount = 100;


std::optional<decltype(std::chrono::system_clock::now() - std::chrono::system_clock::now())> total{};

int matrix[kSize][kSize];

for (int i = 0; i < kIterationsCount; ++i) {

	const auto start = std::chrono::system_clock::now();

	for (int k = 0; k < kSize; ++k) {

		for (int l = 0; l < kSize; ++l) {

			matrix[k][l] = 10;

		}

	}

  
	const auto end = std::chrono::system_clock::now();

	const auto iteration_time = end - start;

	total = total ? *total + iteration_time : iteration_time;

}

std::cout << *total / kIterationsCount << std::endl;

```