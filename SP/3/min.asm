global min

section .text

min:
    push ebp
    mov ebp, esp

    mov esi, [ebp+8]        ; Взятие из стека адреса массива
    mov ecx, [ebp+12]       ; Взятие из стека кол-во элементов  
    mov edx, [esi]          ; edx - минимальный элемент 
    xor edi, edi            ; edi - индекс минимального 
    add esi, 4              ; Переход к следующему элементу
    dec ecx
    cmp ecx , 0
    je end                  ; Переход если второго элемента нет


for:
    mov eax, [esi]          ; Записываем значение элемента в eax
    cmp edx, eax            ;
    jl for2                 ; Если edx меньше то переход

    mov edx, eax            ; eax меньше edx, перезапишем минимальный элемент 

    mov eax, [ebp+12]   
    sub eax, ecx            ; eax - индекс текущего элемента
    mov edi, eax            ; записываем индекс минимального элемента

for2:
    add esi, 4              ; переходим к след. элементу
    loop for 


end:
    mov eax, [ebp+16]
    mov [eax], edi         ; записываем по адресу значения индекса

    mov eax, [ebp+20]
    mov [eax], edx         ; записываем по адресу значение мин. элемента

    mov esp, ebp
    pop ebp
    ret
