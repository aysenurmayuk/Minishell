# minishell

---

## Proje Hakkında (TR)
Bu proje, 42 eğitim programı kapsamında, Bash kabuğunun (shell) kendi versiyonumuzu kodlamayı içerir. Bir kabuğun tüm yaşam döngüsünü (komut okuma, ayrıştırma ve yürütme) kapsayan bu proje, sistem programlamanın temellerini öğretir.

### Teknik Özellikler
- **Lexer & Parser**: Komut satırını anlamlı tokenlara (PIPE, REDIRECT, WORD) bölme ve bir komut ağacı oluşturma.
- **Process Management**: `fork()`, `execve()` ve `waitpid()` fonksiyonları ile süreç yönetimi.
- **Pipe & Redirection**: `|`, `<`, `>`, `>>` ve `<<` (heredoc) operatörlerinin yönetimi.
- **Built-ins**: `echo`, `cd`, `pwd`, `export`, `unset`, `env` ve `exit` komutlarının yeniden yazılması.
- **Signal Handling**: `Ctrl-C`, `Ctrl-D` ve `Ctrl-\` sinyallerinin Bash ile uyumlu şekilde işlenmesi.

### Hata Ayıklama ve Bellek Yönetimi
minishell geliştirilirken bellek sızıntılarını tespit etmek için Valgrind kullanılmıştır. Ancak, sistemdeki readline kütüphanesi kendi içinde kontrolümüz dışında olan bazı sızıntılar bırakabilir. Bu "yalancı sızıntıları" filtrelemek ve sadece kendi yazdığımız kodun doğruluğuna odaklanmak için bir readline.supp (suppression) dosyası kullanılmıştır.

---

## About the Project (EN)
The objective of this project, as part of the 42 curriculum, is to create our own version of the Bash shell. It covers the entire lifecycle of a shell (reading commands, parsing, and execution) and teaches the fundamentals of system programming.

### Technical Specifications
- **Lexer & Parser**: Tokenizing the command line into meaningful units (PIPE, REDIRECT, WORD) and building a command structure.
- **Process Management**: Handling processes using `fork()`, `execve()`, and `waitpid()`.
- **Pipe & Redirection**: Full support for `|`, `<`, `>`, `>>`, and `<<` (heredoc).
- **Built-ins**: Re-implementation of `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Signal Handling**: Managing `Ctrl-C`, `Ctrl-D`, and `Ctrl-\` to match Bash's behavior.

### Debugging & Memory Management
Valgrind was used to detect memory leaks during the development of minishell. However, the system's readline library can leave some internal leaks that are beyond our control. To filter out these "false positives" and focus solely on the integrity of our own code, a readline.supp (suppression) file is utilized.

---

## Kurulum ve Çalıştırma / Installation & Usage

1. Derleme / Compilation
   ```bash
   make
2. Başlatma / Launch
   ```bash
   ./minishell
3. Valgrind ile Test Etme / Testing with Valgrind
   ```bash
   valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell
