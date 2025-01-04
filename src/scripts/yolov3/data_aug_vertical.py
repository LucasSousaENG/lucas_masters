from PIL import Image
import os

def inverter_imagens(pasta):
    # Verifica se a pasta existe
    if not os.path.isdir(pasta):
        print("A pasta especificada não existe.")
        return
    
    # Lista todos os arquivos na pasta
    arquivos = os.listdir(pasta)
    
    # Itera sobre os arquivos
    for arquivo in arquivos:
        # Verifica se o arquivo é uma imagem
        if arquivo.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.gif')):
            caminho_completo = os.path.join(pasta, arquivo)
            
            # Abre a imagem
            imagem = Image.open(caminho_completo)
            
            # Inverte a imagem verticalmente
            imagem_invertida = imagem.transpose(Image.FLIP_TOP_BOTTOM)
            
            # Obtém o nome do arquivo sem a extensão
            nome_arquivo, extensao = os.path.splitext(arquivo)
            
            # Define o novo nome do arquivo
            novo_nome = nome_arquivo + "_invertido" + extensao
            
            # Salva a imagem invertida na mesma pasta
            caminho_novo = os.path.join(pasta, novo_nome)
            imagem_invertida.save(caminho_novo)
            
            print("Imagem {} invertida e salva como {}".format(arquivo, novo_nome))

# Pasta contendo as imagens
pasta = "/home/lucas/Downloads/Dataset_trainning"

# Chama a função para inverter as imagens
inverter_imagens(pasta)
