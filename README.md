# 🎒 Interface de Mochila

Um sistema de inventário em C, inspirado em jogos, com slots, cores no console e animações de carregamento. Ideal para praticar estruturas, enums e manipulação de arrays no C.  

---

## 🔹 Recursos

- Adicionar, remover e listar itens do inventário
- Slots limitados (máximo 10 itens)
- Tipos de itens com cores diferentes no console:
  - Munição 🟦
  - Colete 🟦
  - Arma 🟥
  - Kit Médico 🟩
  - Capacete 🟪
- Animações de inicialização e efeitos de digitação
- Itens iniciais já carregados:
  - Pistola
  - Colete Nível 2
  - Kit Médico x2

---

## 💻 Requisitos

- Windows
- GCC (MinGW) instalado e configurado no PATH
- Console com suporte a UTF-8 e cores (cmd ou PowerShell)

---

## ⚙️ Compilação

No Prompt de Comando ou PowerShell, dentro da pasta do projeto:

```bash
gcc -o mochila.exe main.c
