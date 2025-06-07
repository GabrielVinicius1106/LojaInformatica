# 🖥️ Projeto - Loja de Informática (Terminal em C)

Este é um sistema de vendas simples de uma loja de informática, desenvolvido em linguagem C para rodar no terminal. Ele permite ao usuário simular a compra de componentes de hardware, montar um carrinho, inserir dados pessoais e fechar um pedido com cálculo de descontos e frete.

---

## Requisitos: 

 - Compilador C
 - Git 

## 📦 Funcionalidades

### 🛒 Carrinho de Compras
- Adição de produtos ao carrinho por categoria:
  - Processadores
  - Placas de Vídeo
  - Placas-Mãe
  - Memória RAM
  - Fontes de Alimentação
- Verificação de limite do carrinho
- Exibição de resumo com nome, preço, quantidade e subtotal

### 📍 Endereço do Cliente
- Inserção de nome completo
- Validação da UF (sigla de estado) com conversão automática para maiúsculas
- Inserção da cidade, rua e número

### 💳 Pagamento
- Métodos de pagamento disponíveis:
  - **PIX**: 10% de desconto
  - **Débito**: 5% de desconto
  - **Crédito**: até 12x, sem desconto
- Cálculo de parcelas no crédito

### 🚚 Frete
- **Grátis** para sul do Brasil (SC, PR, RS)
- **5% do total** para demais estados

### 🧾 Finalização do Pedido
- Exibe:
  - Lista de produtos e subtotais
  - Informações do cliente
  - Forma de pagamento e parcelas (se aplicável)
  - Valor do desconto e do frete
  - Valor total do pedido

---

## 📂 Estrutura de Arquivos

- `main.c` — Contém a lógica principal do sistema e o menu.
- `lerInteiroSeguro.h` / `lerInteiroSeguro.c` — Função para entrada segura de inteiros.
- `validarEstado.h` / `validarEstado.c` — Funções para validar e ler uma UF (sigla de estado).

---

## 🔧 Compilação

Primeiramente, instale as dependências **compilador de C** e **git**, e depois instale o repositório:

```bash
git clone https://github.com/GabrielVinicius1106/loja-informatica/
```

Abra o projeto:

```bash
cd ./loja-informatica
```

Para compilar todos os arquivos juntos:

```bash
gcc main.c functions/lerInteiroSeguro.c functions/validarEstado.c -o main
```

## ▶️ Execução

Para executar o projeto:

```bash
./main


