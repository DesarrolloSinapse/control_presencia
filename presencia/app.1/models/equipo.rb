class Equipo < ActiveRecord::Base
	has_many :logs

	validates :nombre, :zona, :ip, :activo, presence: {message: ": Campo obligatorio"}
	validates :ip, format: {with: /#{Regexy::Web::IPv4.new}/ , message: ": Formato incorrecto"}
end