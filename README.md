# 🏕️ Interface de Mochila (Inventory System em C)

[![Inventário](https://img.shields.io/badge/Invent%C3%A1rio-Ativo-brightgreen?style=for-the-badge&logo=trello)](https://github.com/)
[![Linguagem](https://img.shields.io/badge/C-ANSI-blue?style=for-the-badge&logo=c)](https://www.gnu.org/software/gcc/)
[![Plataforma](https://img.shields.io/badge/Windows-Console-lightgrey?style=for-the-badge&logo=windows)](https://www.microsoft.com/pt-br/windows)

Uma interface de inventário em **C** para gerenciar itens de uma mochila, com **menu interativo**, **cores no console**, e **animações de carregamento**. Ideal para jogos ou simulações que precisem de gerenciamento de inventário simples.

---

## ✅ Funcionalidades

- Menu interativo com opções de:
  - Adicionar itens
  - Remover itens
  - Listar itens do inventário
  - Checar peso total (em desenvolvimento)
  - Sair
- Inventário limitado a 10 slots
- Tipos de itens suportados:
  - Munição, Colete, Arma, Kit Médico, Capacete
- Animações e efeitos:
  - Texto digitando (`TypeText`)
  - Barras de carregamento (`LoadingBar`)
  - Itens coloridos por tipo no console

---

## 📦 Estrutura de Dados

```c
typedef struct {
    char name[50];      // Nome do item
    ItemType type;      // Tipo do item
    int count;          // Quantidade
    float weight;       // Peso (não usado atualmente)
} Item;

typedef enum {
    TYPE_AMMO = 1,
    TYPE_VEST,
    TYPE_GUN,
    TYPE_MEDICKIT,
    TYPE_HELMET
} ItemType;

```
## ⚙️ Como Usar
```
Compilação (Windows)
gcc main.c -o mochila.exe
```
````
mochila.exe
````
## ✈ Navegação

- Digite o número da opção desejada no menu
- Para adicionar itens: informe nome, tipo e quantidade
- Para remover itens: digite o nome exato do item

## 📌 Inventário Inicial
O Sistema inicia com os seguintes itens:
| ID | Nome do Item   | Tipo       | Quantidade |
| -- | -------------- | ---------- | ---------- |
| 1  | Pistola        | Arma       | 1          |
| 2  | Colete Nível 2 | Colete     | 1          |
| 3  | Kit Médico     | Kit Médico | 2          |

## 🚀 Melhorias Futuras

- Implementar cálculo de peso total e limite de carga

- Persistência do inventário em arquivo

- Suporte multiplataforma (Linux/Mac)

- Novos tipos de itens (granadas, armas especiais, etc)

- Melhorias na interface visual do console

## 🖼️ Demonstração

- Exemplo do inventário inicial:

```
┌────┬────────────────────────┬────────────────┬───────────────┐
│ ID │ NOME DO ITEM           │ TIPO           │ QUANTIDADE    │
├────┼────────────────────────┼────────────────┼───────────────┤
│ 1  │ Pistola                │ Arma           │ 1             │
│ 2  │ Colete Nível 2         │ Colete         │ 1             │
│ 3  │ Kit Médico             │ Kit Médico     │ 2             │
└────┴────────────────────────┴────────────────┴───────────────┘
```
### Desenvolvido com ❤️ em C para aprendizado e simulações de inventário.
[![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow?style=for-the-badge)](https://github.com/)
[![Linguagem](https://img.shields.io/badge/C-ANSI-blue?style=for-the-badge&logo=c)](https://www.gnu.org/software/gcc/)
[![Plataforma](https://img.shields.io/badge/Windows-Console-lightgrey?style=for-the-badge&logo=windows)](https://www.microsoft.com/pt-br/windows)
[![Licença](https://img.shields.io/badge/licença-MIT-green?style=for-the-badge)](https://opensource.org/licenses/MIT)
[![Versão](https://img.shields.io/badge/versão-1.0.0-blueviolet?style=for-the-badge)](https://github.com/)
