Minitalk é um projeto da École 42 que implementa um programa de comunicação simples entre dois processos usando sinais UNIX. Este projeto consiste em dois executáveis, um servidor e um cliente, que se comunicam através de sinais SIGUSR1 e SIGUSR2.

🚀 Funcionalidades
Comunicação entre dois processos usando sinais UNIX
Uso de SIGUSR1 e SIGUSR2 para transmitir informações
Conversão de mensagens em bits para transmissão eficiente
Recuperação e exibição de mensagens enviadas pelo cliente no servidor
🛠️ Instalação
Para instalar e executar o Minitalk em sua máquina, siga os passos abaixo:

Clone este repositório em sua máquina local:

bash

git clone https://github.com/carl0sfelipe/minitalk-final.git

Compile o projeto usando o Makefile fornecido:

bash

make

Isso gerará dois executáveis, server e client.

📖 Uso
Abra um terminal e execute o servidor:

bash

./server

O servidor exibirá seu PID (Process ID).

Abra outro terminal e execute o cliente, fornecendo o PID do servidor e a mensagem que você deseja enviar:

bash

./client [SERVER_PID] "Your message here"

O servidor receberá e exibirá a mensagem enviada pelo cliente. A comunicação pode continuar até que os processos sejam encerrados.
