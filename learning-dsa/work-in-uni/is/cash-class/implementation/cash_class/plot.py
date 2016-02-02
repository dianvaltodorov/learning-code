import matplotlib.pyplot as plt

PATH = 'plots'


def save_hist_figure(instances, attr, path):
    plt.figure()
    plt.hist([int(inst[attr]) for inst in instances])
    plt.title(attr)
    plt.savefig('{}/{}.png'.format(path, attr))


def save_all_hists(instances):
    save_hist_figure(instances, 'fnlwgt', PATH)
    save_hist_figure(instances, 'capital-gain', PATH)
    save_hist_figure(instances, 'capital-loss', PATH)
    save_hist_figure(instances, 'age', PATH)
    save_hist_figure(instances, 'hours-per-week', PATH)


def plot_hist(instances, attr):
    plt.figure()
    plt.hist([int(inst[attr]) for inst in instances])
    plt.title(attr)
    plt.show()
