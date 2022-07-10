// const { get } = require("node:http");

const scheduler = new Scheduler();
let ID = 1;


const getStorage = () => {
    let processes = [];
    Object.keys(window.localStorage).forEach((key) => {
        let data = JSON.parse(localStorage.getItem(key));
        processes.push(data);
        ID = data.id >= ID ? data.id+1 : ID;
       });
    processes.sort((a, b) => a.id - b.id);

    processes.map(p => {
        const processo = new Processo(p.id, p.arrival, p.burst);
        scheduler.adicionaProcesso(processo);
        Interface.adiciona(processo);
    });

    
}

getStorage();

document.querySelector('#process-form').addEventListener('submit', e => {
    e.preventDefault();

    const tempoChegada = document.querySelector('#tempoChegada').value;
    const tempoExecucao = document.querySelector('#tempoExecucao').value;

    if (!tempoChegada || !tempoExecucao) {
        Interface.showAlert('Complete todos los campos', 'info');
        return;
    }

    const quantidadeDeProcessos = scheduler.processos.length;
    let id = ID++;

    const processo = new Processo(id, tempoExecucao, tempoChegada);
    scheduler.adicionaProcesso(processo);
    Interface.adiciona(processo);
    //guardar en localstorage
    window.localStorage.setItem(id, JSON.stringify({
        id: id,
        arrival: tempoExecucao,
        burst: tempoChegada
    }));

    Interface.clearFields();
});

document.querySelector('#listaDeProcessos').addEventListener('click', e => {
    const id = e.target.parentElement.parentElement.id;
    Interface.deleta(e.target);
    scheduler.removeProcesso(id);
});

document.querySelector('#iniciarEscalonamento').addEventListener('click', async e => {
    e.preventDefault();
    if (scheduler.processos.length == 0) {
        Interface.showAlert('Adicione pelo menos um processo antes de iniciar o escalonamento', 'info');
        return;
    }

    Interface.resetScheduleApplication();

    Interface.disableForm();
    Interface.showProcessProgressBar(scheduler);

    await scheduler.start();

    Interface.clearProcessList();
    Interface.enableForm();
    Interface.changeStartScheduleButton();
    scheduler.reset();
});
