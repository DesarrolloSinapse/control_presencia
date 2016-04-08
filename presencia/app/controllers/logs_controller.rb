class LogsController < ApplicationController
  before_action :set_log, only: [:show, :edit, :update, :destroy]

  # GET /logs
  # GET /logs.json
  def index
    @logs = Log.where('entrada').limit(15).order(id: :desc)
    @logs_s = Log.where.not('entrada').limit(15).order(id: :desc)
  end

  # GET /logs/1
  # GET /logs/1.json
  def show
  end

  def buscar
  end

  def ver_info
    id = params[:usuario_id]
    @usuario = Usuario.find(id)
    f1 = params[:f_ini]
    @f_ini = f1[:f_ini]
    f2 = params[:f_fin]
    @f_fin = f2[:f_fin]

    @aux = 0

    @horas = []
    @acum = 0
    @media = 0

    @registros = Log.where("usuario_id = ? AND tiempo_registro < ? AND tiempo_registro > ?",@usuario.id,@f_fin,@f_ini)
  end

  # GET /logs/new
  def new
    @log = Log.new
  end

  # GET /logs/1/edit
  def edit
  end

  # POST /logs
  # POST /logs.json
  def create
    @log = Log.new(log_params)

    respond_to do |format|
      if @log.save
        format.html { redirect_to @log, notice: 'Log was successfully created.' }
        format.json { render :show, status: :created, location: @log }
      else
        format.html { render :new }
        format.json { render json: @log.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /logs/1
  # PATCH/PUT /logs/1.json
  def update
    respond_to do |format|
      if @log.update(log_params)
        format.html { redirect_to @log, notice: 'Log was successfully updated.' }
        format.json { render :show, status: :ok, location: @log }
      else
        format.html { render :edit }
        format.json { render json: @log.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /logs/1
  # DELETE /logs/1.json
  def destroy
    @log.destroy
    respond_to do |format|
      format.html { redirect_to logs_url, notice: 'Log was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_log
      @log = Log.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def log_params
      params.require(:log).permit(:tiempo_lectora, :tiempo_registro, :equipo_id, :card_id, :usuario_id)
    end
end
