# ARR5_Robotics

##Comandos para usar o git:

##Inicializar:
	$git init.

##Importar uma branch remota (develop, por exemplo):
- $git branch -d [nomebranch]
- $git checkout [nomebranch]
- $git pull origin [nomebranch]

##Criar uma branch para fazer uma melhoria:

- $git branch -c feature/[nomedamelhoria]
- $git checkout feature/[nomedamelhoria]

##Acompanhar suas melhorias:

- $git status
- $git diff
- $git diff [branch_de_comparação]

##Depois que fizer as alterações na sua branch, submeta-as.
- $git add [caminho/do(s)/arquivo(s)]
- $git commit -m "Mensagem descrevendo sua alteração"
- Tente fazer commits para pequenas alterações. Vários commits para uma pull request.

##Quando terminar o seu trabalho na branch, use o seguinte comando:
- $git push origin feature/[nomebranch]


###Coloque login e senha do github e espere submeter. Suas alterações aparecerão no site. Lá você terá que criar uma pull request para o develop. 