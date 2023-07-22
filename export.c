#include "minishell.h"

void handler(char **dp_command)
{
    char **str;

    str = ft_split(dp_command[1], '=');

    // printf("%s\n", str[0]);
    // printf("%s\n", str[1]);
    set_env_variable(str[0], str[1]);

    dp_free(str);
    return ;
}


extern char** environ;  // Declare the 'environ' variable

int set_env_variable(const char* variable, const char* value) {
    // Check if the variable already exists
    char* var_ptr = getenv(variable);
    if (var_ptr != NULL) {
        // Variable already exists, so modify its value
        size_t var_len = strlen(variable);
        size_t val_len = strlen(value);

        // Iterate through the 'environ' array to find the variable
        char** env = environ;
        while (*env != NULL) {
            if (strncmp(*env, variable, var_len) == 0 && (*env)[var_len] == '=') {
                // Found the variable, replace its value
                size_t env_len = var_len + val_len + 2;
                char* new_env = (char*)malloc(env_len);

                char* dest = new_env;
                const char* src = variable;
                while (*src != '\0') {
                    *dest = *src;
                    ++dest;
                    ++src;
                }
                *dest = '=';
                ++dest;

                src = value;
                while (*src != '\0') {
                    *dest = *src;
                    ++dest;
                    ++src;
                }
                *dest = '\0';

                free(*env);          // Free the old string
                *env = new_env;      // Set the new string

                return 0;  // Success
            }
            ++env;
        }
    }

    // Variable does not exist, so add it to 'environ'
    size_t var_len = strlen(variable);
    size_t val_len = strlen(value);

    size_t env_len = var_len + val_len + 2;
    char* new_env = (char*)malloc(env_len);

    char* dest = new_env;
    const char* src = variable;
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '=';
    ++dest;

    src = value;
    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';

    // Count the number of environment variables
    int env_count = 0;
    char** env = environ;
    while (*env != NULL) {
        ++env_count;
        ++env;
    }

    // Allocate memory for the new 'environ' array
    char** new_environ = (char**)malloc((env_count + 2) * sizeof(char*));

    // Copy the existing 'environ' to the new array
    env = environ;
    char** new_env_ptr = new_environ;
    while (*env != NULL) {
        *new_env_ptr = *env;
        ++new_env_ptr;
        ++env;
    }

    // Set the new environment variable
    *new_env_ptr = new_env;
    ++new_env_ptr;
    *new_env_ptr = NULL;

    environ = new_environ;  // Update 'environ'

    return 0;  // Success
}

// int set_env_variable(const char* variable, const char* value) {
//     // Check if the variable already exists
//     char* var_ptr = getenv(variable);
//     if (var_ptr != NULL) {
//         // Variable already exists, so modify its value
//         size_t var_len = strlen(variable);
//         size_t val_len = strlen(value);

//         // Iterate through the 'environ' array to find the variable
//         char** env = environ;
//         while (*env != NULL) {
//             if (strncmp(*env, variable, var_len) == 0 && (*env)[var_len] == '=') {
//                 // Found the variable, replace its value
//                 size_t env_len = var_len + val_len + 2;
//                 char* new_env = (char*)malloc(env_len);

//                 char* dest = new_env;
//                 const char* src = variable;
//                 while (*src != '\0') {
//                     *dest = *src;
//                     ++dest;
//                     ++src;
//                 }
//                 *dest = '=';
//                 ++dest;

//                 src = value;
//                 while (*src != '\0') {
//                     *dest = *src;
//                     ++dest;
//                     ++src;
//                 }
//                 *dest = '\0';

//                 free(*env);          // Free the old string
//                 *env = new_env;      // Set the new string

//                 return 0;  // Success
//             }
//             ++env;
//         }
//     }

//     // Variable does not exist, so add it to 'environ'
//     size_t var_len = strlen(variable);
//     size_t val_len = strlen(value);

//     size_t env_len = var_len + val_len + 2;
//     char* new_env = (char*)malloc(env_len);

//     char* dest = new_env;
//     const char* src = variable;
//     while (*src != '\0') {
//         *dest = *src;
//         ++dest;
//         ++src;
//     }
//     *dest = '=';
//     ++dest;

//     src = value;
//     while (*src != '\0') {
//         *dest = *src;
//         ++dest;
//         ++src;
//     }
//     *dest = '\0';

//     // Count the number of environment variables
//     int env_count = 0;
//     char** env = environ;
//     while (*env != NULL) {
//         ++env_count;
//         ++env;
//     }

//     // Allocate memory for the new 'environ' array
//     char** new_environ = (char**)malloc((env_count + 2) * sizeof(char*));

//     // Copy the existing 'environ' to the new array
//     env = environ;
//     char** new_env = new_environ;
//     while (*env != NULL) {
//         *new_env = *env;
//         ++new_env;
//         ++env;
//     }

//     // Set the new environment variable
//     *new_env = new_env;
//     ++new_env;
//     *new_env = NULL;

//     environ = new_environ;  // Update 'environ'

//     return 0;  // Success
// }