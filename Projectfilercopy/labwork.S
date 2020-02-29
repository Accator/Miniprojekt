  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #


  # timetemplate.asm
  # Written 2015 by F Lundevall
  # Copyright abandonded - this file is in the public domain.


.global delay
.global time2string
.global hexasc

.data
.text
    
    
############################# DELAY ########################
delay:
    addi $t1, $zero, 0       #for loop i
    li $t2, 5000000 #antal forloops 4777
    #$a0        antal ms
whileloop:
    beq $a0,$zero, whileexit    #efter "ms" antal varv
    nop
    addi $a0, $a0, -1
                    #lägger till varvet innan den hoppar
forloop:
    addi $t1, $t1, 1
    bgt $t1,$t2, whileloop
    nop
    j forloop
    nop
        
whileexit:
    jr $ra
    nop            #hoppa tillbaka.

############################## HEXA KONVERTERARE ###########################
    
  hexasc:
      move $t7,$a0
  
     blt  $t7,10,low
     nop
             
     addi $v0,$t7,0x37
     jr $ra
     nop
 
      low:
          addi $v0,$t7,0x30
          jr $ra
          nop
          
 
    
time2string:

    #var sparas stacken?
    #fungerar t reg annorlunda?
    PUSH $s2
    PUSH $s1
    PUSH $ra
    
    move $s1,$a0    #adressen flyttas till s1
    move $s2,$a1
    
    #SUPP
    
    
    
    #1
    andi $t0, $s2, 0xffff
    beq $t0, $zero, supp
    nop
    
    srl $a0,$t0,12
    jal hexasc
    nop
    move $t1,$v0
    sb $t1,0($s1) #spara byten "t1" på plats 0 i registret med adressen s1, de registret är a0. Varför fungerar inte om man
    #2
    andi $t0, $s2, 0xfff
    srl $a0,$t0,8
    jal hexasc
    nop
    move $t1,$v0
    sb $t1,1($s1)
    #colon
    li $t0, 0x3a
    sb $t0, 2($s1)
    #3
    andi $t0, $s2, 0xff
    srl $a0,$t0,4
    jal hexasc
    nop
    move $t1,$v0
    sb $t1,3($s1)
    #4
    andi $t0, $s2, 0xf
    srl $a0,$t0,0

    jal hexasc
    nop
    move $t1,$v0
    sb $t1,4($s1)
    
    
    andi $t7, $s2, 1
    beq $t7,1,odd
    nop
        
    
even:
    
    li $t1,0x45
    sb $t1,5($s1)
    
    
    
    #Null
    li $t0, 0x0
    sb $t0,6($s1)
    j finnishline
    nop

odd:
    li $t1,0x44
    sb $t1,5($s1)


    
    #Null
    li $t0, 0x0
    sb $t0,6($s1)
    j finnishline
    nop
    
supp:
    
    #1
    addi $t1,$zero, 0x48
    sb $t1,0($s1)
    
    addi $t1,$zero, 0x4f
    sb $t1,1($s1)
    
    addi $t1,$zero, 0x55
    sb $t1,2($s1)
    
    addi $t1,$zero, 0x52
    sb $t1,3($s1)

    
    
    
    #Null
    li $t0, 0x0
    sb $t0,4($s1)
     #j finnishline
    

    
    
finnishline:
    POP $ra
    POP $s1
    POP $s2
    
    jr $ra
    nop
