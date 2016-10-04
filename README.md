# sta-to-csv

Ferramenta CLI converter um arquivo STA em CSV

## Prerequisitos

* CMake `sudo apt-get install cmake`
* Pacote build-essential `sudo apt-get install build-essential`
* gcc 5 ou superior (suporte a C++14)

## Compilação

Navegue para o diretório do projeto e execute os seguintes comandos:

```bash
mkdir -p build/release
cd build/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
make
```

Se tudo ocorrer corretamento, o binário sta-to-csv será gerado no diretorio build/release

## Instalação

Ainda no diretório build/release, execute o comando:

```bash
sudo make install
```

Será instalado o binário em: /usr/local/bin/sta-to-csv

## Executando

```bash
sta-to-csv foo-schema.REF foo-data.TXT > foo-data.csv
```

PS.: Ainda será implementado o controle do arquivo de saída via parâmetro
(atualmente, o resultado é obtido apenas via saída padrão).

## Comandos úteis durante empacotamento debian

 * dpkg-architecture -L
 * ldd my_binary_file
 * dpkg --get-selections | grep libc
