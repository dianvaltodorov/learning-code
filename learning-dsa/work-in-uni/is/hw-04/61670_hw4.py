import random
# EXAMPLE 1
# items = [(90, 150),
#          (130, 35),
#          (1530, 200),
#          (500, 160),
#          (150, 60),
#          (680, 45),
#          (270, 60),
#          (390, 40),
#          (230, 30),
#          (520, 10),
#          (110, 70),
#          (320, 30),
#          (240, 15),
#          (480, 10),
#          (730, 40),
#          (420, 70),
#          (430, 75),
#          (220, 80),
#          (70, 20),
#          (180, 12),
#          (40, 50),
#          (300, 10),
#          (900, 1),
#          (2000, 150)]
# N = len(items)
# M = 5000
# weights = [it[0] for it in items]
# values = [it[1] for it in items] 

POPULATION_SIZE = 4
MAX_GENERATIONS = 10000000
PERCENT = 0.9
CHOSEN_GENERATIONS = (10, 11, 17, 19)
MUTATION_PROBABILITY = 0.7
CROSSOVER_PROBABILITY = 0.9

# Example 2
M = 5
N = 3
values = [2, 5, 3]
weights = [3, 1, 2]


# Input
# M = input()
# N = input()
# weights = []
# values = []

# for i in xrange(N):
#     w = input()
#     weights.append(w)
#     v = input()
#     values.append(v)

def initial_population(population_size, number_of_items):
    population = [[random.randint(0, 1) for _ in xrange(number_of_items)]
                  for p in xrange(population_size)]
    return population


def get_fitness_values(population, values, weights, capacity):
    fitness_values = []
    for chromosome in population:
        value = 0
        weight = capacity + 1
        while weight > capacity:
            weight = 0
            value = 0
            taken_indexes = []  # the ones in the list
            for idx, take_flag in enumerate(chromosome):
                if take_flag == 1:
                    value += values[idx]
                    weight += weights[idx]
                    taken_indexes += [idx]
            if weight > capacity:
                chromosome[random.choice(taken_indexes)] = 0
        fitness_values += [value]
    return fitness_values


def mode(items):
    return max([items.count(x) for x in set(items)])


def fit_enough(fitness_values, percent):
    return float(mode(fitness_values)) / len(fitness_values) >= percent


def crossover(chromosome1, chromosome2, probability):
    lucky = random.randint(range(len(chromosome1)))
    return chromosome1[:lucky] + chromosome2[lucky:]


def mutate(chromosome, probability):
    for i in xrange(len(chromosome)):
        n = random.random()
        if n <= probability:
            if chromosome[i] == 0:
                chromosome[i] = 1
            else:
                chromosome[i] = 0


def roulette_selection(population, fitness_values):
    population_size = len(population)
    totalFit = sum(fitness_values)
    lucky = random.randint(0, totalFit)
    temp_sum = 0
    fit1 = 0
    for i in xrange(population_size):
        temp_sum += fitness_values[i]
        if temp_sum >= lucky:
            chromosome1 = population.pop(i)  # remove chromosome from population
            fit1 = fitness_values.pop(i)  # remove chromosome from fitness
            break
    tempSum = 0
    lucky = random.randint(0, totalFit)
    for i in xrange(population_size):
        temp_sum += fitness_values[i]
        if tempSum >= lucky:
            chromosome2 = population[i]
            population += [chromosome1]
            fitness_values += [fit1]
            return (chromosome1, chromosome2)


def next_generation(population, fitness_values, mutation_probability, crossover_probability):
    new_popluation = []
    new_popluation += [select_fittest(population, fitness_values)[0]]
    while len(new_popluation) < len(population):
        (mate1, mate2) = roulette_selection(population, fitness_values)
        c = crossover(mate1, mate2, crossover_probability)
        m = mutate(c, mutation_probability)
        new_popluation += [m]
    return new_popluation


def select_fittest(population, fitness_values):
    best = 0
    for idx, fitness in enumerate(fitness_values):
        if fitness > fitness_values[best]:
            best = idx
    return population[best], fitness_values[best]


def knapsack(weights, values, capacity,
             fitness_percent=PERCENT,
             population_size=POPULATION_SIZE,
             max_generations=MAX_GENERATIONS,
             mutation_probability=MUTATION_PROBABILITY,
             crossover_probability=CROSSOVER_PROBABILITY):
    population = initial_population(population_size, len(values))
    generation = 0
    fitness_values = get_fitness_values(population, values, weights, capacity)
    print generation
    # import ipdb; ipdb.set_trace()
    while not fit_enough(fitness_values, fitness_percent) and generation < max_generations:
        generation = generation + 1
        if generation in CHOSEN_GENERATIONS:
            print select_fittest(population, fitness_values)[1]
        population = next_generation(population, fitness_values,  mutation_probability, crossover_probability)
        fitness_values = get_fitness_values(population, values, weights, capacity)
    return select_fittest(population, fitness_values)[1]


knapsack(weights, values, M)