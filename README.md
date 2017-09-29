# sta-to-csv

Ferramenta CLI para converter um arquivo STA em CSV

## Dependências para construção

* CMake: `sudo apt-get install cmake`
* Pacote build-essential (ou semelhante): `sudo apt-get install build-essential`
* gcc 5 ou superior (suporte a C++14 ou superior)
* Qt 5+ (GUI)

## Compilação

Navegue para o diretório do projeto e execute os seguintes comandos:

#### Debug
```bash
mkdir -p build/debug
cd build/debug
cmake -DCMAKE_BUILD_TYPE=Release ../..
make
```

#### Release
```bash
mkdir -p build/release
cd build/release
cmake ../..
make
```

## Instalação

Ainda no diretório de construção, execute o comando:

```bash
sudo make install
```

Será instalado o binário em: /usr/local/bin/sta-to-csv

## Executando

```bash
sta-to-csv foo-schema.REF foo-data.TXT > foo-data.csv
```

## Exemplos

```c++
#include <iostream>
#include <sta/sta-parser.h>

using namespace std;

int main(int argc, char* argv[])
{
	string refFilepath{"ref"s};
	string dataFilePath{"data"s};
	string outputFilePath{"output.csv"s};

	STAParser parser{refFilepath, dataFilePath, outputFilePath};

	auto filtrarEventosDestaque = [](const string& value) -> bool {
		if (value == "300300" || value == "300301" || value == "300302") {
			return true;
		}
		return false;
	};

	parser.setMultipleFilterMode(STAParser::MultipleFilterMode::OR);
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(1)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(2)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(3)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(4)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(5)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(6)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(7)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(8)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(9)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(10)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(11)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(12)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(13)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(14)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(15)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(16)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(17)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(18)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(19)"s, filtrarEventosDestaque});
	parser.addFilter(STAFilter{"GR-CODIGO-EVENTO(20)"s, filtrarEventosDestaque});

	parser.parse();

	return 0;
}
```

PS.: Ainda será implementado o controle do arquivo de saída via parâmetro
(atualmente, o resultado é obtido apenas via saída padrão).

## Construindo pacote debian

* debuild -b -uc -us
* use dch --create from the devscripts package to create changelogs in the correct format

## Comandos úteis durante empacotamento debian

 * dpkg-architecture -L
 * ldd my_binary_file
 * dpkg --get-selections | grep libc
