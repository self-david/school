class Scheduler {
    constructor() {
        this.processos = [];
        this.filaDeProntos = new Fila();
        this.processosConcluidos = [];
        this.processoExecutando = null;
    }

    reset() {
        this.processos = [];
        this.filaDeProntos = new Fila();
        this.processosConcluidos = [];
        this.processoExecutando = null;
    }

    totalDeProcessos() {
        return this.processos.length;
    }

    totalTempoDeExecucao() {
        let total = 0;
        for (let i = 0; i < this.processos.length; i++) {
            total += this.processos[i].tempoExecucao;
        }

        return total;
    }

    walkPercentage() {
        return this.totalTempoDeExecucao() / 100;
    }

    adicionaProcesso(processo) {
        return this.processos.push(processo);
    }

    removeProcesso(id) {
        let processoIndice = 0;
        for (let i = 0; i < this.processos.length; i++) {
            let processo = this.processos[i];
            if (processo.id == id) {
                processoIndice = i;
                break;
            }
        }

        return this.processos.splice(processoIndice, 1);
    }
updateProcessStatus
    finalizaProcesso(processo) {
        processo.status = 'Concluído';
        this.processosConcluidos.push(processo);
    }

    insereProcessoNaFilaDePronto(tempoAtualExecucao) {
        for (let i = 0; i < this.processos.length; i++) {
            let processo = this.processos[i];
            if (processo.tempoChegada == tempoAtualExecucao) {
                processo.status = 'Pronto';
                this.filaDeProntos.insere(processo);
            }
        }
    }

    sleep(ms) {
        return new Promise(resolve => setTimeout(resolve, ms));
    }

    async start() {
        let tempoAtualExecucao = 0;
        console.log(this.processos);
        while (this.processos.length !== this.processosConcluidos.length) {
            this.insereProcessoNaFilaDePronto(tempoAtualExecucao);
            await this.sleep(2000);
            await Interface.updateProcessProgressBar(this);
            await Interface.updateTempoAtualExecucao(tempoAtualExecucao);

            console.log('Escalonamento DEBUG - Tiempo: ', tempoAtualExecucao);
            console.log('Escalonamento DEBUG - Fila de Prontos: ', this.filaDeProntos);

            if (this.processoExecutando) {
                this.processoExecutando.status = 'Pronto';
                this.filaDeProntos.insere(this.processoExecutando);
            }

            console.log('Escalonamento DEBUG - Fila de Prontos: ', this.filaDeProntos);

            this.processoExecutando = this.filaDeProntos.next();

            console.log('Escalonamento DEBUG - Processo em execucion: ', this.processoExecutando);
            if (!this.processoExecutando) {
                tempoAtualExecucao++;
                continue;
            }

            this.processoExecutando.status = 'Ejecutando';
            this.processoExecutando.diminuiTempoRestante();

            await Interface.updateProcessProgressBar(this);
            if (this.processoExecutando.tempoRestante == 0) {
                this.finalizaProcesso(this.processoExecutando);
                this.processoExecutando = null;
            }

            await Interface.updateProcessStatus(this);

            tempoAtualExecucao++;
            console.log('Escalonamento DEBUG - Processos: ', this.processos);
        }

        await Interface.updateProcessStatus(this);
        console.log('END');
        console.log(this.processosConcluidos);
    }
}
