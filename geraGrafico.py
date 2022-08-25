import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('files/Airlines_grafico.csv')
fig = plt.figure()
ax = fig.add_axes([0,0,1,1])

# Atribuindo os valores do dataframe para as variáveis
airlines = df['Airlines']
delays = df[' Media de atrasos']

plt.figure(figsize=(10,6))

# Rótulo do eixo x
plt.xlabel("Linhas aéreas")

# Rótulo do eixo y
plt.ylabel("Media de atrasos")

# Adiciona titulo ao gráfico
plt.title("Media de atrasos por linha aérea")

# Adicionando as variáveis para o gráfico
plt.plot(airlines, delays, 'r')

# Mostrar o gráfico
plt.show()
